/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack() : min_(0)
    {
    }

    void push(int x)
    {
        if (stack_.size() == 0 || x < min_)
            min_ = x;
        stack_.push_back(x);
    }

    void pop()
    {
        if (stack_[stack_.size() - 1] == min_)
        {
            cout << 11 << endl;
            refindMin();
        }
        stack_.erase(stack_.end() - 1);
    }

    int top()
    {
        return stack_[stack_.size() - 1];
    }

    int getMin()
    {
        return min_;
    }

private:
    vector<int> stack_;
    int min_;

    void refindMin()
    {
        if (stack_.size() <= 1)
            return;
        min_ = stack_[0];
        for (int i = 1; i < stack_.size() - 1; ++i)
        {
            if (stack_[i] < min_)
            {
                min_ = stack_[i];
            }
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
