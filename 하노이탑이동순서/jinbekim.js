const input = require('fs')
	.readFileSync('/dev/stdin', 'utf8')
	.toString()
	.trim().split('\n');
let str = "";
let answer = 0;
function recur(n, from, to, middle) {
    if (n === 0) {
        return;
    }
    recur(n - 1, from, middle, to);
    answer++;
    str += `${from} ${to}` + "\n";
    recur(n - 1, middle, to, from);
}
recur(input[0], 1, 3, 2);
console.log(answer);
console.log(str);
