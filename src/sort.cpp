#include "tweet.h"

void bubbleSort(std::vector<Tweet>& tweets, const std::string& sortBy, bool ascending) 
{
    for (size_t i = 0; i < tweets.size() - 1; ++i) {
        for (size_t j = 0; j < tweets.size() - i - 1; ++j) {
            bool condition = false;

            // Match sortBy strings exactly to the test cases for both retweetCount and favoriteCount
            if (sortBy == "retweetCount") {
                condition = ascending ? (tweets[j].retweetCount > tweets[j + 1].retweetCount) 
                                      : (tweets[j].retweetCount < tweets[j + 1].retweetCount);
            } else if (sortBy == "favoriteCount") {  // Corrected to match test case exactly
                condition = ascending ? (tweets[j].favoriteCount > tweets[j + 1].favoriteCount) 
                                      : (tweets[j].favoriteCount < tweets[j + 1].favoriteCount);
            } else if (sortBy == "tweetID") {
                condition = ascending ? (tweets[j].tweetID > tweets[j + 1].tweetID) 
                                      : (tweets[j].tweetID < tweets[j + 1].tweetID);
            }

            // Swap if the condition is true
            if (condition) {
                std::swap(tweets[j], tweets[j + 1]);
            }
        }
    }
}




void insertionSort(std::vector<Tweet>& tweets, const std::string& sortBy, bool ascending) 
{
    for (size_t i = 1; i < tweets.size(); ++i) {
        Tweet key = tweets[i];
        int j = i - 1;

        // Adjust comparison conditions based on sortBy attribute and ascending flag
        while (j >= 0) {
            bool condition = false;
            if (sortBy == "retweetCount") {
                condition = ascending ? (tweets[j].retweetCount > key.retweetCount) 
                                      : (tweets[j].retweetCount < key.retweetCount);
            } else if (sortBy == "favoriteCount") {
                condition = ascending ? (tweets[j].favoriteCount > key.favoriteCount) 
                                      : (tweets[j].favoriteCount < key.favoriteCount);
            } else if (sortBy == "tweetID") {
                condition = ascending ? (tweets[j].tweetID > key.tweetID) 
                                      : (tweets[j].tweetID < key.tweetID);
            }

            if (!condition) {
                break;
            }
            tweets[j + 1] = tweets[j];
            --j;
        }
        tweets[j + 1] = key;
    }
}

void merge(std::vector<Tweet>& tweets, int left, int mid, int right, const std::string& sortBy, bool ascending) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors
    std::vector<Tweet> leftArray(n1);
    std::vector<Tweet> rightArray(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        leftArray[i] = tweets[left + i];
    for (int i = 0; i < n2; i++)
        rightArray[i] = tweets[mid + 1 + i];

    int i = 0, j = 0, k = left;

    // Merging the arrays while sorting
    while (i < n1 && j < n2) {
        bool condition = false;

        if (sortBy == "retweetCount") {
            condition = ascending ? (leftArray[i].retweetCount <= rightArray[j].retweetCount) 
                                  : (leftArray[i].retweetCount >= rightArray[j].retweetCount);
        } else if (sortBy == "favoriteCount") {
            condition = ascending ? (leftArray[i].favoriteCount <= rightArray[j].favoriteCount) 
                                  : (leftArray[i].favoriteCount >= rightArray[j].favoriteCount);
        } else if (sortBy == "tweetID") {
            condition = ascending ? (leftArray[i].tweetID <= rightArray[j].tweetID) 
                                  : (leftArray[i].tweetID >= rightArray[j].tweetID);
        }

        if (condition) {
            tweets[k] = leftArray[i];
            i++;
        } else {
            tweets[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray
    while (i < n1) {
        tweets[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray
    while (j < n2) {
        tweets[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<Tweet>& tweets, int left, int right, const std::string& sortBy, bool ascending) 
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(tweets, left, mid, sortBy, ascending);
        mergeSort(tweets, mid + 1, right, sortBy, ascending);

        // Merge the sorted halves
        merge(tweets, left, mid, right, sortBy, ascending);
    }
}