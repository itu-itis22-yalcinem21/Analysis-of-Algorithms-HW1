#include "tweet.h"

int binarySearch(const std::vector<Tweet>& tweets, long long key, const std::string& sortBy) 
{
    int left = 0;
    int right = tweets.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Compare based on the specified attribute
        if (sortBy == "tweetID") {
            if (tweets[mid].tweetID == key) {
                result = mid; // Store the index
                right = mid - 1; // Continue searching on the left to find the first occurrence
            } else if (tweets[mid].tweetID < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else if (sortBy == "retweet_count") {
            if (tweets[mid].retweetCount == key) {
                result = mid;
                right = mid - 1;
            } else if (tweets[mid].retweetCount < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else if (sortBy == "favorite_count") {
            if (tweets[mid].favoriteCount == key) {
                result = mid;
                right = mid - 1;
            } else if (tweets[mid].favoriteCount < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return result; // Return the index of the first match or -1 if not found
}

int countAboveThreshold(const std::vector<Tweet>& tweets, const std::string& metric, int threshold) {
    int count = 0;

    for (const Tweet& tweet : tweets) {
        if (metric == "favoriteCount") {  // Ensure this matches the test input
            if (tweet.favoriteCount > threshold) {
                count++;
            }
        } else if (metric == "retweetCount") {  // Ensure this matches the test input
            if (tweet.retweetCount > threshold) {
                count++;
            }
        }
    }

    return count;
}