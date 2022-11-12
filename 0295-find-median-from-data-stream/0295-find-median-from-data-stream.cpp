class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
        median_iter = mp.begin();
    }

    void addNum(int num)
    {
        ++mp[num];
        if (lower_equal_size == 0 || num <= median_iter->first)
        {
            ++lower_equal_size;
            auto &val = median_iter->second;
            if (lower_equal_size >= greater_size + 2 * val)
            {
                greater_size += val;
                lower_equal_size -= val;
                --median_iter;
            }
        }
        else
        {
            ++greater_size;
            if (lower_equal_size < greater_size)
            {
                ++median_iter;
                lower_equal_size += median_iter->second;
                greater_size -= median_iter->second;
            }
        }
    }

    double findMedian()
    {
        if (lower_equal_size != greater_size)
        {
            return median_iter->first;
        }
        else
        {
            return (static_cast<double>(median_iter->first) + static_cast<double>(next(median_iter)->first)) / 2;
        }
    }
    map<int, short> mp;
    map<int, short>::iterator median_iter;
    short lower_equal_size = 0;
    short greater_size = 0;
};