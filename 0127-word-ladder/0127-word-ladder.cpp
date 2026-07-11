class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
  unordered_set<string> s(wordList.begin(),wordList.end());
  queue<pair<string,int>> q;
  q.push({beginWord,1});
  s.erase(beginWord); 
  while(!q.empty())
  {
    string currword= q.front().first;
    int steps= q.front().second;
    q.pop();
  if(currword==endWord)
  return steps;
  
  for(int i = 0 ;i<beginWord.size();i++)
  {
     char original = currword[i];
     for( char ch = 'a';ch<='z';ch++)
     {
        currword[i]=ch;
        if(s.find(currword)!=s.end())
        {
            s.erase(currword);
            q.push({currword,steps+1});

        }
     }
     currword[i]=original;
  }

    }
    return 0;
    }
};