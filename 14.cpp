#include <vector>
#include <algorithm>

struct Range
{
    int start;
    int end;
    Range(int s, int e) : start(s), end(e) {}
};

class RangeModule
{
private:
    std::vector<Range> ranges;

public:
    void addRange(int left, int right)
    {
        std::vector<Range> newRanges;
        Range range(left, right);
        bool inserted = false;

        for (const auto &r : ranges)
        {
            if (r.end < range.start)
            {
                newRanges.push_back(r);
            }
            else if (r.start > range.end)
            {
                if (!inserted)
                {
                    newRanges.push_back(range);
                    inserted = true;
                }
                newRanges.push_back(r);
            }
            else
            {
                range.start = std::min(range.start, r.start);
                range.end = std::max(range.end, r.end);
            }
        }

        if (!inserted)
        {
            newRanges.push_back(range);
        }

        ranges = std::move(newRanges);
    }

    bool queryRange(int left, int right)
    {
        for (const auto &r : ranges)
        {
            if (r.start <= left && r.end >= right)
            {
                return true;
            }
        }
        return false;
    }

    void removeRange(int left, int right)
    {
        std::vector<Range> newRanges;

        for (const auto &r : ranges)
        {
            if (r.end <= left || r.start >= right)
            {
                newRanges.push_back(r);
            }
            else
            {
                if (r.start < left)
                {
                    newRanges.push_back(Range(r.start, left));
                }
                if (r.end > right)
                {
                    newRanges.push_back(Range(right, r.end));
                }
            }
        }

        ranges = std::move(newRanges);
    }
};
// Range