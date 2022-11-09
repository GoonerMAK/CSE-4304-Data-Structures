#include<bits/stdc++.h>
using namespace std;

#define d 26      ///  amount of input characters

void rabinKarp(char pattern[], char text[], int q)          ///  q = prime number
{
  int pattern_size = strlen(pattern);
  int text_size = strlen(text);
  int i, j, flag = 0;
  int hash_pattern = 0;    ///  hash value for pattern
  int hash_text = 0;       ///  hash value for text
  int h = 1;


  for (i = 0; i < pattern_size; i++)    /// Calculating hash value for pattern and text for first window of text
  {
    hash_pattern = (d * hash_pattern + pattern[i]) % q;
    hash_text = (d * hash_text + text[i]) % q;
  }

  /// Finding the match
  for (i = 0; i <= text_size - pattern_size; i++)
  {
    if (hash_pattern == hash_text)     ///  checking for first window of text (at first... then moving right one by one)
    {
      for (j = 0 ; j < pattern_size ; j++)     ///  now to check the characters
      {
        if (text[i + j] != pattern[j])
          break;
      }

      if (j == pattern_size)         ///  if the characters were same
      {
          flag = 1;
          cout << "Pattern is found at position: " << i + 1 << endl;
      }

    }

    if (i < text_size - pattern_size)     /// hash value for next window of text
    {
      hash_text = (d * (hash_text - text[i] * h) + text[i + pattern_size]) % q;

      if (hash_text < 0)
        hash_text = (hash_text + q);           /// making it positive if it gives negative value
    }
  }

  if(flag == 0)
  {
      cout << "Pattern is not found" <<  endl;
  }
}

int main()
{
  char text[] = "ABCCDDAEFG";
  char pattern[] = "CD";
  int q = 13;                        ///  prime number
  rabinKarp(pattern, text, q);
}
