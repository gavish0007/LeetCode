class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int ans = INT_MAX;

        // Earliest finish among land rides
        int landMinEnd = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            landMinEnd = min(landMinEnd,
                             landStartTime[i] + landDuration[i]);
        }

        // Land -> Water
        for (int j = 0; j < waterStartTime.size(); j++) {
            ans = min(ans,
                      max(landMinEnd, waterStartTime[j]) +
                      waterDuration[j]);
        }

        // Earliest finish among water rides
        int waterMinEnd = INT_MAX;
        for (int j = 0; j < waterStartTime.size(); j++) {
            waterMinEnd = min(waterMinEnd,
                              waterStartTime[j] + waterDuration[j]);
        }

        // Water -> Land
        for (int i = 0; i < landStartTime.size(); i++) {
            ans = min(ans,
                      max(waterMinEnd, landStartTime[i]) +
                      landDuration[i]);
        }

        return ans;
    }
};