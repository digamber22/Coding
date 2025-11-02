// https://cses.fi/problemset/task/2166

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node
{
  ll sum, pref;
};

const ll NEG = LLONG_MIN / 4; // safe "negative infinity" for this problem

vector<ll> a;
vector<Node> seg;

Node merge(Node left, Node right)
{
  Node res;
  res.sum = left.sum + right.sum;
  res.pref = max(left.pref, left.sum + right.pref);
  return res;
}

void sg_tree_build(ll idx, ll low, ll high)
{
  if (low == high)
  {
    seg[idx] = {a[low], max(a[low], 0LL)}; // allow empty prefix (>= 0)
    return;
  }

  ll mid = (low + high) / 2;
  sg_tree_build(2 * idx + 1, low, mid);
  sg_tree_build(2 * idx + 2, mid + 1, high);

  seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
}

void update(ll idx, ll low, ll high, ll pos, ll val)
{
  if (low == high)
  {
    seg[idx] = {val, max(val, 0LL)};
    a[pos] = val;
    return;
  }

  ll mid = (low + high) / 2;

  if (pos <= mid)
    update(2 * idx + 1, low, mid, pos, val);
  else
    update(2 * idx + 2, mid + 1, high, pos, val);

  seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
}

Node query(ll idx, ll low, ll high, ll l, ll r)
{
  // completely outside
  if (high < l || low > r) return {0, NEG};

  // completely inside
  if (low >= l && high <= r) return seg[idx];

  ll mid = (low + high) / 2;
  Node left = query(2 * idx + 1, low, mid, l, r);
  Node right = query(2 * idx + 2, mid + 1, high, l, r);

  return merge(left, right);
}

void solve()
{
  ll n, q;
  cin >> n >> q;

  a.assign(n + 1, 0);
  seg.assign(4 * n + 5, Node{0, NEG}); // initialize with NEG pref

  for (ll i = 1; i <= n; i++)
    cin >> a[i];

  sg_tree_build(0, 1, n);

  while (q--)
  {
    ll type;
    cin >> type;
    if (type == 1)
    {
      ll k, u;
      cin >> k >> u;
      update(0, 1, n, k, u);
    }
    else
    {
      ll l, r;
      cin >> l >> r;
      cout << query(0, 1, n, l, r).pref << '\n';
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t = 1;
  while (t--)
    solve();
  return 0;
}
