class Solution {
public:
    int mirrorReflection(int p, int q) {
        bool up=true,down =false;
        int x=0,y=0;
        if(q==0)
            return 0;
        else if(p==q)
            return 1;
        else
        {
            for(int i=0;i<1000;i++)
            {
			// for going up 
                if(up==true)
                {
                    if(i%2==0)
                        x = x+p,y=y+q;
                    else
                        x = x-p,y=y+q;
                    // y goes out the box but x never go out of the box
					//  so we have to keep y inside the box 
                    if(y>p)
                    {
                        y = 2*p -y;
                        down =true;
                        up = false;
                    }
                }
				// for going down
                else if(down==true)
                {
                    if(i%2==0)
                        x = x+p,y=y-q;
                    else
                        x = x-p,y=y-q;
                    
                    if(y<0)
                    {
                        y =(-1)*y;
                        up =true;
                        down =  false;
                    }
                }
                cout<<x<<" "<<y<<" "<<up<<" "<<down<<endl;
                if(x==0&&y==p)
                    return 2;
                else if(x==p&&y==0)
                    return 0;
                else if(x==p&&y==p)
                    return 1;
                
            }
        }
        return 1;
    }
};