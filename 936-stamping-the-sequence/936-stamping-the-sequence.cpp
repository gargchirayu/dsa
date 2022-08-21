class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int target_len = target.size();
        int stamp_len = stamp.size();
        vector<bool> processed(target_len, false);
        stack<int> to_stamp_reversed;
        queue<int> to_process;
        // Map all missing and matching indices for a position i of target.
        vector<pair<unordered_set<int>, unordered_set<int>>> position_match_missing;
        // Iterate through all possible windows (the stamp must fit within the window).
        for (int i = 0; i <= target_len - stamp_len; i++)
        {
            unordered_set<int> match_indices;
            unordered_set<int> missing_indices;
            for (int j = 0; j < stamp_len; j++)
            {
                if (target[i + j] == stamp[j])
                    match_indices.insert(i + j);
                else
                    missing_indices.insert(i + j);
            }
            position_match_missing.push_back({match_indices, missing_indices});
            
            // Check if the current position matches the stamp completely.
            if (missing_indices.empty())
            {
                // The fully matched windows are getting stamped the last.
                to_stamp_reversed.push(i);
                
                for (int j = i; j < i + stamp_len; j++)
                {
                    processed[j] = true;
                    to_process.push(j);
                }
            }
        }
        
        // Mark all windows that are affected and store the indices
        // for windows that have no missing indices.
        while (!to_process.empty())
        {
            int i = to_process.front();
            to_process.pop();
            
            // Loop through all starting indices and enqueue all match indices,
            // once an affected window was fully processed.
            for (int j = max(0, i - stamp_len + 1); j <= min(target_len - stamp_len, i); j++)
            {
                if (position_match_missing[j].second.count(i))
                {
                    // Window starting at j is affected by i.
                    position_match_missing[j].second.erase(i);
                    if (position_match_missing[j].second.empty())
                    {
                        // The affected window was processed, therefore can stamp at j.
                        to_stamp_reversed.push(j);
                        for (int m : position_match_missing[j].first)
                        {
                            if (processed[m]) continue;
                            
                            // By enqueueing the match indices, we check for the subsequent affected windows
                            // of the processed affected window.
                            to_process.push(m);
                            processed[m] = true;
                        }
                    }
                }
            }
        }
        
        for (bool p : processed)
            if (!p)
                return {};
        
        vector<int> stamp_indices;
        while (!to_stamp_reversed.empty())
        {
            stamp_indices.push_back(to_stamp_reversed.top());
            to_stamp_reversed.pop();
        }
        
        return stamp_indices;
    }
};