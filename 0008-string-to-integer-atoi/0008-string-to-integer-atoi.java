class Solution {
    public int myAtoi(String s) {
        long num = 0;
        int sign = 1;
        boolean started = false;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            // skip leading spaces
            if (!started && c == ' ') continue;

            // sign handling
            if (!started && (c == '+' || c == '-')) {
                sign = (c == '-') ? -1 : 1;
                started = true;
                continue;
            }

            // digits using switch
            int d;
            switch (c) {
                case '0': d = 0; break;
                case '1': d = 1; break;
                case '2': d = 2; break;
                case '3': d = 3; break;
                case '4': d = 4; break;
                case '5': d = 5; break;
                case '6': d = 6; break;
                case '7': d = 7; break;
                case '8': d = 8; break;
                case '9': d = 9; break;
                default: return (int)(sign * num); // char found → stop
            }

            started = true;
            num = num * 10 + d;

            // overflow check
            if (sign == 1 && num > Integer.MAX_VALUE)
                return Integer.MAX_VALUE;
            if (sign == -1 && -num < Integer.MIN_VALUE)
                return Integer.MIN_VALUE;
        }

        return (int)(sign * num);
    }
}
