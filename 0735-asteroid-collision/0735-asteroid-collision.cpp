class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        // Stack stores asteroids that are still alive.
        stack<int> st;

        // Process each asteroid one by one.
        for(int asteroid : asteroids)
        {
            // Assume the current asteroid survives.
            bool alive = true;

            //----------------------------------------------------
            // Collision happens only when:
            // Stack top is moving right (>0)
            // Current asteroid is moving left (<0)
            //----------------------------------------------------
            while(alive &&
                  !st.empty() &&
                  st.top() > 0 &&
                  asteroid < 0)
            {
                //------------------------------------------------
                // Compare sizes using absolute values.
                //------------------------------------------------

                // Case 1:
                // Current asteroid is bigger.
                // Example:
                // Stack top = 5
                // Current = -8
                //
                // 5 explodes.
                if(abs(asteroid) > st.top())
                {
                    st.pop();

                    // Continue checking because
                    // current asteroid may collide
                    // with previous right-moving asteroids.
                }

                // Case 2:
                // Both are equal.
                // Example:
                // 8 and -8
                //
                // Both explode.
                else if(abs(asteroid) == st.top())
                {
                    st.pop();

                    // Current asteroid also explodes.
                    alive = false;
                }

                // Case 3:
                // Stack top is bigger.
                // Example:
                // 10 and -5
                //
                // Current asteroid explodes.
                else
                {
                    alive = false;
                }
            }

            //----------------------------------------------------
            // If current asteroid survived all collisions,
            // push it into the stack.
            //----------------------------------------------------
            if(alive)
                st.push(asteroid);
        }

        //--------------------------------------------------------
        // Stack stores answer from bottom to top.
        // Convert it into vector.
        //--------------------------------------------------------
        vector<int> ans(st.size());

        for(int i = st.size() - 1; i >= 0; i--)
        {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};