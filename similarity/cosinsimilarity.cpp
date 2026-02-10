/**
 * Cosine Similarity for Text Documents
 * Time Complexity: O(n) for word processing
 * Space Complexity: O(n) for storing word vectors
 * Measures similarity between two documents using cosine of angle
 */

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

/**
 * Read words from file
 * @param filename File to read
 * @return Vector of words
 */
vector<string> readWords(const string& filename) {
    ifstream file(filename);
    vector<string> words;
    string word;
    
    while (file >> word) {
        words.push_back(word);
    }
    
    return words;
}

/**
 * Get unique words from two documents
 * @param words1 Words from first document
 * @param words2 Words from second document
 * @return Vector of unique words
 */
vector<string> getUniqueWords(const vector<string>& words1, const vector<string>& words2) {
    unordered_set<string> uniqueSet;
    
    for (const auto& word : words1) {
        uniqueSet.insert(word);
    }
    for (const auto& word : words2) {
        uniqueSet.insert(word);
    }
    
    return vector<string>(uniqueSet.begin(), uniqueSet.end());
}

/**
 * Create frequency vector for words
 * @param words Document words
 * @param uniqueWords All unique words
 * @return Frequency vector
 */
vector<int> createFrequencyVector(const vector<string>& words, const vector<string>& uniqueWords) {
    unordered_map<string, int> freqMap;
    
    for (const auto& word : words) {
        freqMap[word]++;
    }
    
    vector<int> freqVector;
    for (const auto& uniqueWord : uniqueWords) {
        freqVector.push_back(freqMap[uniqueWord]);
    }
    
    return freqVector;
}

/**
 * Calculate cosine similarity between two vectors
 * @param vec1 First vector
 * @param vec2 Second vector
 * @return Cosine similarity (0 to 1)
 */
double cosineSimilarity(const vector<int>& vec1, const vector<int>& vec2) {
    double dotProduct = 0.0;
    double magnitude1 = 0.0;
    double magnitude2 = 0.0;
    
    for (size_t i = 0; i < vec1.size(); i++) {
        dotProduct += vec1[i] * vec2[i];
        magnitude1 += vec1[i] * vec1[i];
        magnitude2 += vec2[i] * vec2[i];
    }
    
    magnitude1 = sqrt(magnitude1);
    magnitude2 = sqrt(magnitude2);
    
    if (magnitude1 == 0.0 || magnitude2 == 0.0) return 0.0;
    
    return dotProduct / (magnitude1 * magnitude2);
}

int main() {
    cout << "Cosine Similarity for Text Documents\n";
    cout << string(50, '=') << "\n";
    
    // Example with hardcoded documents
    vector<string> doc1 = {"this", "is", "a", "sample", "document"};
    vector<string> doc2 = {"this", "document", "is", "another", "example"};
    
    cout << "Document 1 words: " << doc1.size() << "\n";
    cout << "Document 2 words: " << doc2.size() << "\n\n";
    
    // Get unique words
    vector<string> uniqueWords = getUniqueWords(doc1, doc2);
    cout << "Total unique words: " << uniqueWords.size() << "\n\n";
    
    // Create frequency vectors
    vector<int> freq1 = createFrequencyVector(doc1, uniqueWords);
    vector<int> freq2 = createFrequencyVector(doc2, uniqueWords);
    
    // Display frequency vectors
    cout << "Frequency Vector 1: ";
    for (int freq : freq1) cout << freq << " ";
    cout << "\n";
    
    cout << "Frequency Vector 2: ";
    for (int freq : freq2) cout << freq << " ";
    cout << "\n\n";
    
    // Calculate cosine similarity
    double similarity = cosineSimilarity(freq1, freq2);
    
    cout << "Cosine Similarity: " << similarity << "\n";
    cout << "Similarity Percentage: " << (similarity * 100) << "%\n";
    
    return 0;
}
