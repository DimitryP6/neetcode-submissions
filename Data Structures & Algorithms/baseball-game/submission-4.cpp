class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> pointStack;
        int sum = 0;
        for (const string& op : operations) {
            if (op == "+") {
                int firstTop = pointStack.top();
                pointStack.pop();
                int newTop = firstTop + pointStack.top();
                pointStack.push(firstTop);
                pointStack.push(newTop);
                sum += newTop;
            } else if (op == "D") {
                pointStack.push(pointStack.top() * 2);
                sum += pointStack.top();
            } else if (op == "C") {
                sum -= pointStack.top();
                pointStack.pop();
            } else {
                pointStack.push(stoi(op));
                sum += pointStack.top();
            }
        }
        return sum;
    }
};