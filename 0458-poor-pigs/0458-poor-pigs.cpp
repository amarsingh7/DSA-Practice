class Solution {
public:
    int poorPigs(int buckets, int mtd, int mtt) {
        return ceil(log2(buckets)/log2((mtt/mtd)+1));
    }
};