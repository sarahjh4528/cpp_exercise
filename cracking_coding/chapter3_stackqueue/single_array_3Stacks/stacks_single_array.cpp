int buffer[300];

Class Stack
{
    int start_index, end_index, top_index;
    int *arr;
    Stack(int s, int e, int *buf):start_index(s), end_index(e), top_index(-1), arr(buf) {
        top = NULL;
    }

    bool push(int data) {
        if (top_index+1 != end_index) {
            if (top_index < start_index)
                top_index = start_index;
            else
                ++top_index;
            arr[top_index] = data;
            return true;
        } else {
            // Stack full, print message
            return false;
        }
    }

    bool pop(int &returnData) {
        if (top_index >= start_index) {
            returnData = arr[top_index];
            --top_index;
            return true;
        } else {
            //Stack empty
            return false;
        }
    }

    bool peek(int &peekData) {
        if (top_index >= start_index) {
            peekData = arr[top_index];
            return true;
        } else {
            return false;
        }
    }
}
