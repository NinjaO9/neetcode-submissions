class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[5] = {0};
        int mb = 0;
        for (const auto& c : text)
        {
            switch(c)
            {
                case 'b':
                freq[0]++;
                break;
                case 'a':
                freq[1]++;
                break;
                case 'l':
                freq[2]++;
                break;
                case 'o':
                freq[3]++;
                break;
                case 'n':
                freq[4]++;
                break;
                default: break;
            }
        }   
        mb = min(freq[0], freq[1]);
        mb = min(mb, freq[2]/2);
        mb = min(mb, freq[3]/2);
        return min(mb, freq[4]);


    }
};