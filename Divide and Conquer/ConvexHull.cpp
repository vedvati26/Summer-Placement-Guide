class Solution {
public:
struct pt {
    double x, y;
};

static bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}
vector<vector<int>>FindConvexHull(vector<vector<int>>points_list){
	vector<pt>a;
	for(auto i: points_list){
		pt p;
		p.x = i[0];
		p.y = i[1];
		a.push_back(p);
	}
	convex_hull(a);
	sort(a.begin(), a.end(), &cmp);
	vector<vector<int>>ans;
	for(auto i: a){
		vector<int>v = {int(i.x), int(i.y)};
		ans.push_back(v);
	}
	if(ans.size() <= 2)return {{-1}};
	return ans;
}
};
/*
class Solution {
public:
    bool ori(vector<int> &a, vector<int> &b, vector<int> &c){
        return (long long)(c[1] - b[1])*(b[0] - a[0]) <= (long long)(b[1] - a[1])*(c[0] - b[0]); 
    }
    vector<vector<int>> FindConvexHull(vector<vector<int>>& trees) { 
        int n = trees.size();
        if(n < 3) return {{-1}}; 
        sort(trees.begin(), trees.end());
        vector<int> vis(n, 0), uh, lh;
        for(int i = 0; i < n; i++){
            // upper hull
            int szu = uh.size();
            while(szu >= 2 and ori(trees[uh[szu-2]], trees[uh[szu-1]], trees[i])) 
                vis[uh[szu-1]]--, szu--, uh.pop_back();
            uh.push_back(i);
            vis[i]++;
            // lower hull
            int szl = lh.size();
            while(szl >= 2 and ori(trees[lh[szl-2]], trees[lh[szl-1]], trees[n-i-1])) 
                vis[lh[szl-1]]--, szl--, lh.pop_back();
            lh.push_back(n-i-1);
            vis[n-i-1]++;
        }    
        vector<vector<int>> ch;
        for(int i = 0; i < n; i++) if(vis[i]) ch.push_back(trees[i]);
        return ch;
    } 
};*/