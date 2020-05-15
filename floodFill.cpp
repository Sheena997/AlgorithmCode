/*
733. ͼ����Ⱦ
��һ���Զ�ά���������ʾ��ͼ����ÿһ��������ʾ��ͼ��������ֵ��С����ֵ�� 0 �� 65535 ֮�䡣

����һ������ (sr, sc) ��ʾͼ����Ⱦ��ʼ������ֵ���� ���У���һ���µ���ɫֵ newColor������������ɫ���ͼ��

Ϊ�������ɫ�������ӳ�ʼ���꿪ʼ����¼��ʼ��������������ĸ�����������ֵ���ʼ������ͬ���������ص㣬�����ټ�¼���ĸ������Ϸ������������ص������Ƕ�Ӧ�ĸ�����������ֵ���ʼ������ͬ���������ص㣬�������ظ��ù��̡��������м�¼�����ص����ɫֵ��Ϊ�µ���ɫֵ��

��󷵻ؾ�����ɫ��Ⱦ���ͼ��

ʾ�� 1:

����: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
���: [[2,2,2],[2,2,0],[2,0,1]]
����: 
��ͼ������м䣬(����(sr,sc)=(1,1)),
��·�������з������������ص����ɫ�������ĳ�2��
ע�⣬���½ǵ�����û�и���Ϊ2��
��Ϊ�����������������ĸ����������ʼ�����������ص㡣
ע��:

image �� image[0] �ĳ����ڷ�Χ [1, 50] �ڡ�
�����ĳ�ʼ�㽫���� 0 <= sr < image.length �� 0 <= sc < image[0].length��
image[i][j] �� newColor ��ʾ����ɫֵ�ڷ�Χ [0, 65535]�ڡ�
ͨ������13,380�ύ����24,881

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/flood-fill/
*/
class Solution {
public:
    int path[4][2] = {{-1, 0}, {1, 0},{0, -1}, {0, 1}};
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor, vector<vector<int>>& flag)
    {
        //��ǰ��Ⱦɫ
        image[sr][sc] = newColor;
        //���ΪȾ��ɫ��
        flag[sr][sc] = 1;
        
        //���ĸ���������
        for(int i = 0; i < 4; ++i)
        {
            int nr = sr + path[i][0];
            int nc = sc + path[i][1];
            
            //���Խ��������
            if(nr < 0 || nr >= image.size() || nc < 0 || nc >= image[0].size())
                continue;
            
            if(image[nr][nc] == oldColor && flag[nr][nc] == 0)
                dfs(image, nr, nc, newColor, oldColor, flag);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.empty())
            return image;
        
        int oldColor = image[sr][sc];
        vector<vector<int>> flag(image.size(), vector<int>(image[0].size(), 0));
        
        dfs(image, sr, sc, newColor, oldColor, flag);
        
        return image;
    }
};