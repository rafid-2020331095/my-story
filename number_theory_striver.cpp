#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 10000000;       // Example value, adjust as needed
const int PRIME = 1000000007; // Example prime number, adjust as needed
int fact[N], invfact[N];
void extractnumber(int n)
{
    while (n > 0)
    {
        int x = n % 10;
        cout << x;
        n = n / 10;
    }
}
void numberofdigit(int n)
{
    int x = log10(n) + 1;
    cout << x;
}
void revereseanumber(int n)
{
    int num = 0;
    while (n > 0)
    {
        int x = n % 10;
        num = num * 10 + x;
        n = n / 10;
    }
    cout << num;
}
void palindrome(int n)
{
    int dupli = n;
    int num = 0;
    while (n > 0)
    {
        int x = n % 10;
        num = num * 10 + x;
        n = n / 10;
    }
    if (dupli == num)
        cout << "tr";
    else
        cout << "fal";
}
void armstrong(int n)
{
    int dupli = n;
    int num = 0;
    while (n > 0)
    {
        int x = n % 10;
        num = num + x * x * x;
        n = n / 10;
    }
    if (dupli == num)
        cout << "tr";
    else
        cout << "fal";
}
void divisors(int n)
{
    vector<int> ans;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {

            ans.push_back(i);
            if (n / i != i)
            {

                ans.push_back(n / i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto it : ans)
    {
        cout << it << " ";
    }
}
void prime(int n)
{
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if (n / i != i)
            {
                cnt++;
            }
        }
        if (cnt > 2)
            break;
    }
    if (cnt == 2)
        cout << "tr";
    else
        cout << "fals";
}
void gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0)
        cout << b;
    else
        cout << a;
}
void primefactor(int n)
{
    vector<int> ans;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            while (n % i == 0)
            {
                n = n / i;
            }
        }
    }
    if (n != 1)
        ans.push_back(n);
    for (auto it : ans)
    {
        cout << it << " ";
    }
}
void sieveoferatos(int n)
{
    vector<int> v(n + 1, 1);
    for (int i = 2; i * i <= n; i++)
    {
        if (v[i] == 1)
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                v[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (v[i] == 1)
        {
            cout << i << " ";
        }
    }
}
void countprimeinrange(int l, int r)
{
    int n = 1e5;
    vector<int> v(n + 1, 1);
    for (int i = 2; i * i <= n; i++)
    {
        for (int j = i * i; j <= n; j = j + i)
        {
            v[j] = 0;
        }
    }
    int cnt = 0;
    v[0] = 0, v[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        cnt += v[i];
        v[i] = cnt;
    }
    int primecount = v[r] - v[l - 1];
    cout << primecount;
}
void primefactorquery(vector<int> &ara)
{
    int n = 1e5;
    int spf[n + 1];
    for (int i = 0; i <= n; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }

    for (int i = 0; i < ara.size(); i++)
    {
        int m = ara[i];
        while (m != 1)
        {
            cout << spf[m] << " ";
            m = m / spf[m];
        }
        cout << endl;
    }
}

void powerfunction(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = res * a;
            n--;
        }
        else
        {
            a = a * a;
            n = n / 2;
        }
    }
    cout << res;
}
int pw(int a, int n, int m)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (1ll * res * a) % m;
            n--;
        }
        else
        {
            a = (1ll * a * a) % m;
            n = n / 2;
        }
    }
    // cout << res;
    return res;
}

// fermets little theorem=x^-1=x^m-2 %m;
// (a/x)%m== (a*multiinverse(x))% m;

int multipli_inverse(int x, int m)
{
    return pw(x, m - 2, m);
}

void init()
{
    int p = PRIME;
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (1LL * i * fact[i - 1]) % p;
    }
    invfact[N - 1] = pw(fact[N - 1], p - 2, p);
    for (int i = N - 2; i >= 0; i--)
    {
        // refer to utkarsh gupta video
        invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % p;
    }
}

int ncr(int n, int r)
{

    if (r > n || r < 0 || n < 0)
        return 0;
    // return fact[n] * invfact[r] % PRIME * invfact[n - r] % PRIME;
    int result = fact[n];
    result = (1LL * result * invfact[r]) % PRIME;
    result = (1LL * result * invfact[n - r]) % PRIME;
    return result;
}
int main()
{
    int n = 780, a, b;
    // cin >> n;
    // cin >> a >> b;
    // extractnumber(n);
    // numberofdigit(n);
    // revereseanumber(n);
    // palindrome(n);
    // armstrong(n);
    // divisors(n);
    // cout << endl;
    // prime(n);
    // gcd(a, b);
    // primefactor(n);
    // sieveoferatos(n);
    // int l, r;
    // cin >> l >> r;
    // countprimeinrange(l, r);
    // vector<int> v = {24, 105, 23, 1000, 17};
    // primefactorquery(v);
    // int b1 = 4, n1 = 3;
    // powerfunction(b1, n1);
    // int k = INT_MAX - 10000000;
    // cout << k << 2;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        if (ans % 4 == 0)
            ans = n / 4;
        else
            ans = (n / 4) + 1;

        cout << ans << endl;
    }
}
void pr_binary(int num)
{
    for (int i = 10; i >= 0; i--)
        cout << ((num >> i) & 1);
    cout << endl;
}