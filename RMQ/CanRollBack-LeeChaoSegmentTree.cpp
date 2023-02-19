#define ll long long

using namespace std;

struct Line{
	int m,b;
};
struct LeeChaoSegmentTree{
	
	Line segment;
	
	int lch,rch;
};

vector<LeeChaoSegmentTree> seg;

int queries[300001];

ll ans[300001];

int n;

stack <pair<int,LeeChaoSegmentTree>> st;

ll solve(ll val,Line u)
{
	if( u.m == 0 && u.b == -2e9 ) return -2e18;
	
	return u.m * val + u.b;	
}
void update(Line val,int index,int l,int r)
{
	int mid = l + ( r - l ) / 2;
	
	if( val.m == seg[index].segment.m && val.b == seg[index].segment.b ) return;
	
	if( solve(mid,val) >= solve(mid,seg[index].segment) )
	{	
	
		st.push({index,seg[index]});
	
		if( l == r )
		{
			seg[index].segment = val;
			
			return;
		}
	
		if( val.m > seg[index].segment.m ) // 丟到左邊
		{
			if( seg[index].lch == 0 ) seg[index].lch = seg.size() , seg.push_back({seg[index].segment,0,0});
			else update(seg[index].segment,seg[index].lch,l,mid);
		}
		else
		{
			if( seg[index].rch == 0 ) seg[index].rch = seg.size() , seg.push_back({seg[index].segment,0,0});
			else update(seg[index].segment,seg[index].rch,mid+1,r);
		}
		
		seg[index].segment = val;
	}
	else
	{
		st.push({index,seg[index]});
		
		if( l == r )
		{
			return;
		}
		
		if( seg[index].segment.m > val.m )
		{
			if( seg[index].lch == 0 ) seg[index].lch = seg.size() , seg.push_back({val,0,0});
			else update(val,seg[index].lch,l,mid);
		}
		else
		{
			if( seg[index].rch == 0 ) seg[index].rch = seg.size() , seg.push_back({val,0,0});
			else update(val,seg[index].rch,mid+1,r);
		}
	}
}
ll query(int pos,int index,int l,int r)
{
	if( l == r )
	{
		return solve(pos,seg[index].segment);
	}
	
	int mid = l + ( r - l ) / 2;
	
	ll num = solve(pos,seg[index].segment);
	
	if( pos <= mid && seg[index].lch != 0 )
	{
		return max( num , query(pos,seg[index].lch,l,mid) );
	}
	else if( pos > mid && seg[index].rch != 0 )
	{
		return max( num , query(pos,seg[index].rch,mid+1,r) );
	}
	else
	{
		return solve(pos,seg[index].segment);
	}
}
void modify(int ql,int qr,pair<int,int> val,int index,int l,int r)
{
	if( ql <= l && r <= qr )
	{
		time_seg[index].push_back(val);
		
		return;
	}
	
	int mid = ( l + r ) / 2;
	
	if( qr <= mid ) modify(ql,qr,val,index+1,l,mid);
	else if( ql > mid ) modify(ql,qr,val,index+2*(mid-l+1),mid+1,r);
	else
	{
		modify(ql,qr,val,index+1,l,mid);
		modify(ql,qr,val,index+2*(mid-l+1),mid+1,r);
	}
}