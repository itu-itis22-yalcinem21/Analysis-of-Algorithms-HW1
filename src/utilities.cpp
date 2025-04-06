#include "tweet.h"

std::vector<Tweet> readTweetsFromFile(const std::string& filename) 
{
    std::vector<Tweet> tweets;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return tweets;
    }
    
    std::string line;
    // Skip header line if present
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string item;
        Tweet tweet;
        
        // Read tweetID
        std::getline(ss, item, ',');
        tweet.tweetID = std::stoll(item);
        
        // Read retweetCount
        std::getline(ss, item, ',');
        tweet.retweetCount = std::stoi(item);
        
        // Read favoriteCount
        std::getline(ss, item, ',');
        tweet.favoriteCount = std::stoi(item);
        
        tweets.push_back(tweet);
    }
    file.close();
    return tweets;
}

void writeTweetsToFile(const std::string& filename, const std::vector<Tweet>& tweets) 
{
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }
    
    // Write header
    file << "tweetID,retweet_count,favorite_count\n";
    
    // Write each tweet's data
    for (const auto& tweet : tweets) {
        file << tweet.tweetID << "," << tweet.retweetCount << "," << tweet.favoriteCount << "\n";
    }
    file.close();
}