//한 줄 입력

let fs = require('fs');
let input = fs
	.readFileSync('/dev/stdin')
	.toString()
	.trim();

const str = input.toUpperCase().split('');
const dic = {};
const max = {
	key: '?',
	count: 0
};

for (key of str) {
	if (key === '\n') break;
	dic[key] = dic[key] ? dic[key] + 1 : 1;
}

for (key in dic) {
	if (max.count < dic[key]) {
		max.key = key;
		max.count = dic[key];
	} else if (max.count === dic[key]) {
		max.key = '?';
	}
}
console.log(max.key);
