#include <vector>
using namespace std;
using Mat = vector<vector<int>>;

void Rotate90(Mat& arr)
{
    vector<vector<int>> temp = arr;
    const int n = temp.size() - 1; 
    for(int r = 0 ; r < arr.size(); r++)
        for(int c = 0; c < arr.size(); c++)
            arr[r][c] = temp[n-c][r];
}

bool CheckByPos(int off_r, int off_c, const Mat& key, Mat& resize_lock )
{
    for(int r = 0; r < key.size(); ++r)
        for(int c = 0; c < key.size(); ++c)
            resize_lock[r + off_r][c + off_c] += key[r][c];

    bool result = true;

    const int N = resize_lock.size() / 3;
    for(int r = N; r < N * 2; ++r)
        for(int c = N; c < N * 2; ++c)
            if(resize_lock[r][c] != 1) 
                result = false;

    for(int r = 0; r < key.size(); ++r)
        for(int c = 0; c < key.size(); ++c)
            resize_lock[r + off_r][c + off_c] -= key[r][c];

    return result;
}

bool Check(const Mat& key, Mat& resize_lock)
{
    const int N = resize_lock.size() / 3;
    for(int r = 0; r < N * 2; ++r)
        for(int c = 0; c < N * 2; ++c)
            if(CheckByPos(r,c,key, resize_lock) == true)
                return true;
    return false;

}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    const int N = lock.size();
    Mat resize_lock(lock.size() * 3, vector<int>(lock.size() * 3));
    for(int r = N; r < 2 * N; ++r)
    {
        for(int c = N; c < 2 * N; ++c)
        {
            resize_lock[r][c] = lock[r-N][c-N];
        }
    }
    for(int i = 0; i < 4; ++i)
    {
        if(Check(key, resize_lock) == true)
        {
            answer = true;
            break;
        }
        Rotate90(key);
    }
    return answer;
}