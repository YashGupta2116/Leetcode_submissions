class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string directory;
        stringstream ss(path);
        while (getline(ss, directory, '/')) {
            if (directory == "" || directory == ".") {
                continue;
            }

            if (directory == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } 
            else {
                st.push_back(directory);
            }
        }

        directory = "/";
        for (int i = 0; i < st.size(); i++) {
            directory += st[i];
            if (i != st.size()-1) {
                directory += '/';
            }
        }

        return directory;
    }
};