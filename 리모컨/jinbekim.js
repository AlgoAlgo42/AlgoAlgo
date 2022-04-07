const input = require('fs')
	.readFileSync('/dev/stdin', 'utf8')
	.toString()
	.trim()
	.split('\n');

const channelTo = +input[0];
let channelFrom = 100;
const brokenButtonCount = +input[1];
let workingButtons = new Array(10).fill(0).map((_, i) => i);
if (brokenButtonCount) {
	const brokenButtons = Array.from(input[2].split(' ')).map(Number);
	brokenButtons.forEach((val) => {
		workingButtons.splice(val, 1);
	});
}
answer = Math.abs(channelTo - channelFrom);

function init(tmpChannel, count) {
	if (count > 6) return;
	if (count) {
		answer = Math.min(answer, count + Math.abs(channelTo - tmpChannel));
	}
	workingButtons.forEach((val) => {
		init(tmpChannel * 10 + val, count + 1);
	});
}

init(0, 0);

console.log(answer);
