#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <sstream>

using namespace std;

void reverseString() {
    string str;

    cout << "Enter a string: ";

    cin.ignore();

    getline(cin, str);

    string reversed = "";

    int length = str.length();

    for(int i=length-1 ; i>=0 ; i--)
    {
        reversed += str[i];
    }

    cout << "Reversed sentence: " << reversed << endl;
}


void findMostFrequent()
{
    int n;
    cout << "How many numbers do you want to enter? ";
    cin >> n;

    if(n <= 0) {
        cout << "Invalid size!" << endl;
        return;
    }

    int arr[1000];

    cout << "Enter " << n << " numbers: ";
    for(int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
    }

    int maxCount = 0;
    int mostFrequent = arr[0];

    for(int i=0 ; i<n ; i++)
    {
        int k = 0;
        for(int j=0 ; j<n ; j++)
        {
            if(arr[j]==arr[i])
            {
                k++;
            }
        }

        if(k > maxCount)
        {
            maxCount = k;
            mostFrequent = arr[i];
        }
    }

    cout << "The most frequent number is: " << mostFrequent << endl;
}


void checkPrime()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if(n <= 1)
    {
        cout << n << " is not a prime number." << endl;
        return;
    }

    bool isPrime = true;

    for(int i=2 ; i*i<=n ; i++)
    {
        if(n%i==0)
        {
            isPrime = false;
            break;
        }
    }

    if(isPrime)
    {
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }
}

void sumMatrix()
{
    int num;

    cout << "Enter the size of the matrix: ";

    cin >> num;

    if(num <= 0)
    {
        cout << "Invalid size!" << endl;
        return;
    }

    int arr[num][num];

    cout << "Enter the elements of matrix:" << endl;

    for(int i=0 ; i<num ; i++)
    {
        for(int j=0 ; j<num ; j++)
        {
            cin >> arr[i][j];
        }
    }
    int sum = 0;

    for(int i=0 ; i<num ; i++)
    {
        sum += arr[i][i];
    }

    cout << "Sum of the main diameters of the matrix is: " << sum << endl;
}


void sortWordsInSentence() {
    string sentence;
    cout << "Enter a sentence: ";
    cin.ignore();
    getline(cin, sentence);

    if(sentence.empty())
    {
        cout << "The sentence is empty." << endl;
        return;
    }

    stringstream ss(sentence);
    vector<string> words;
    string word;

    while(ss >> word)
    {
        words.push_back(word);
    }

    auto compare = [](const string& a, const string& b)
    {
        string a_lower = a;
        string b_lower = b;
        transform(a_lower.begin(), a_lower.end(), a_lower.begin(), ::tolower);
        transform(b_lower.begin(), b_lower.end(), b_lower.begin(), ::tolower);
        return a_lower < b_lower;
    };

    sort(words.begin(), words.end(), compare);

    cout << "Sorted words: ";
    for(size_t i=0 ; i<words.size(); i++)
    {
        cout << words[i];
        if(i < words.size() - 1) cout << " ";
    }
    cout << endl;
}

int main()
{
    int num;

    do
    {
        cout << "\n--- Menu ---" << endl;
        cout << "What do you want to do?" << endl;
        cout << "1. Reverse the string" << endl;
        cout << "2. Frequent number" << endl;
        cout << "3. Checking the prime number" << endl;
        cout << "4. Sum of the main diameters of the matrix" << endl;
        cout << "5. Ordering words in a sentence" << endl;
        cout << "6. Exit" << endl;

        cin >> num;

        switch(num)
        {
            case 1:
                reverseString();
                break;
            case 2:
                findMostFrequent();
                break;
            case 3:
                checkPrime();
                break;
            case 4:
                sumMatrix();
                break;
            case 5:
                sortWordsInSentence();
                break;
            case 6:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option! Please choose a number between 1 and 6." << endl;
                break;
        }

    }while(num!=6);

    return 0;
}

