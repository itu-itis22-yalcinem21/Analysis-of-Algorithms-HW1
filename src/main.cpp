#include "tweet.h"
#include <chrono>

/*
void measureSortingTimes(const std::vector<Tweet>& tweets) {
    std::vector<Tweet> sortedTweets;
    
    // Measure Bubble Sort times
    {
        sortedTweets = tweets;
        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(sortedTweets, "retweetCount", true);  // Ascending
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationAsc = end - start;

        sortedTweets = tweets;
        start = std::chrono::high_resolution_clock::now();
        bubbleSort(sortedTweets, "retweetCount", false);  // Descending
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationDesc = end - start;

        std::cout << "Bubble Sort - Ascending: " << durationAsc.count() << " seconds, Descending: " << durationDesc.count() << " seconds\n";
    }

    // Measure Insertion Sort times
    {
        sortedTweets = tweets;
        auto start = std::chrono::high_resolution_clock::now();
        insertionSort(sortedTweets, "retweetCount", true);  // Ascending
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationAsc = end - start;

        sortedTweets = tweets;
        start = std::chrono::high_resolution_clock::now();
        insertionSort(sortedTweets, "retweetCount", false);  // Descending
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationDesc = end - start;

        std::cout << "Insertion Sort - Ascending: " << durationAsc.count() << " seconds, Descending: " << durationDesc.count() << " seconds\n";
    }

    // Measure Merge Sort times
    {
        sortedTweets = tweets;
        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(sortedTweets, 0, sortedTweets.size() - 1, "retweetCount", true);  // Ascending
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationAsc = end - start;

        sortedTweets = tweets;
        start = std::chrono::high_resolution_clock::now();
        mergeSort(sortedTweets, 0, sortedTweets.size() - 1, "retweetCount", false);  // Descending
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationDesc = end - start;

        std::cout << "Merge Sort - Ascending: " << durationAsc.count() << " seconds, Descending: " << durationDesc.count() << " seconds\n";
    }
}
*/

int main() {
    // Load tweets from a CSV file
    // std::vector<Tweet> tweets = readTweetsFromFile("data/permutations/tweetsNS.csv");  // Replace "tweets.csv" with your actual file path

    // Measure sorting times for ascending and descending orders
    // measureSortingTimes(tweets);

    return 0;
}