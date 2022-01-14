/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function(s) {
    const Max = 2147483647;
    const Min = -2147483648;
    let sign = 1;
    let idx = 0;
    let num = 0;
    
    while (s[idx] == ' ') idx++;
    if (s[idx] === '+' || s[idx] === '-'){
        if (s[idx] === '-') sign = -1;
        idx++;
    }
    while (48 <= s.charCodeAt(idx) && s.charCodeAt(idx) <= 57 )
    {
        num = num * 10 + s[idx] * sign;
        if (num > Max)
            return Max;
        if (num < Min)
            return Min;
        idx++;
    }
    
    return num
};