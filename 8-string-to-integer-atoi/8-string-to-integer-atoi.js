/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function(s) {
    const Max = 2147483647;
    const Min = -2147483648;
    const num = parseInt(s);
        if (num > Max)
            return Max;
        if (num < Min)
            return Min;
        if (isNaN(num))
            return 0;

    return num
};