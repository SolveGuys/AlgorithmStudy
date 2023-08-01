#include <iostream>
#include <string>

using namespace std;

int l, c;
char arr[16];
char tmp[16];
char vowels[] = { 'a', 'e', 'i', 'o', 'u' };

void MergeSort(int st, int en);
void Merge(int st, int md, int en);
void DFS(const string& cur, int idx, int vowelCnt, int consonantCnt);
bool IsVowel(char c);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> l >> c;

    for (int i = 0; i < c; ++i)
    {
        cin >> arr[i];
    }

    MergeSort(0, c); // sort(arr, arr + c);

    for (int i = 0; i < c; ++i)
    {
        bool isVowel = IsVowel(arr[i]);

        DFS(string(1, arr[i]), i, isVowel, 1 - isVowel);
    }
}

void MergeSort(int st, int en)
{
    if (st + 1 == en)
    {
        return;
    }

    int md = (st + en) / 2;

    MergeSort(st, md);
    MergeSort(md, en);
    Merge(st, md, en);
}

void Merge(int st, int md, int en)
{
    int i = st;
    int j = md;
    int k = st;

    while ((i < md) && (j < en))
    {
        if (arr[i] <= arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
        }
    }

    while (i < md)
    {
        tmp[k++] = arr[i++];
    }

    while (j < en)
    {
        tmp[k++] = arr[j++];
    }

    for (int l = st; l < en; ++l)
    {
        arr[l] = tmp[l];
    }
}

void DFS(const string& cur, int idx, int vowelCnt, int consonantCnt)
{
    if (cur.length() == l)
    {
        if ((vowelCnt >= 1) && (consonantCnt >= 2))
        {
            cout << cur << '\n';
        }

        return;
    }

    for (int i = idx + 1; i < c; ++i)
    {
        if (IsVowel(arr[i]))
        {
            DFS(cur + arr[i], i, vowelCnt + 1, consonantCnt);
        }
        else
        {
            DFS(cur + arr[i], i, vowelCnt, consonantCnt + 1);
        }
    }
}

bool IsVowel(char c)
{
    for (char vowel : vowels)
    {
        if (c == vowel)
        {
            return true;
        }
    }

    return false;
}
