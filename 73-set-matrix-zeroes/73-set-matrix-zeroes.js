/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    let zeroArr = [];
    
    matrix.forEach((val, row) => {
        val.forEach((val, col) => {
            if (val === 0) zeroArr.push([row, col]);
        });
    });
    for (const element of zeroArr) {
        matrix.forEach((val, idx, arr) => {
            val[element[1]] = 0
            if (idx === element[0]) {
                for (let i = 0,len = matrix[idx].length; i < len; ++i )
                    matrix[idx][i] = 0;
            }
        });
    }
    return zeroArr;
};