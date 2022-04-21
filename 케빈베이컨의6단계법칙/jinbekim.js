const input = require('fs')
	.readFileSync('/dev/stdin')
	.toString()
	.trim()
	.split('\n');

const [N, M] = input[0].split(' ').map(Number);

const relationship = Array.from({ length: N + 1 }, (val) =>
	new Array(N + 1).fill(Infinity)
);

function init(relationNum) {
	for (let i = 1; i <= relationNum; ++i) {
		const [person1, person2] = input[i].split(' ').map(Number);
		relationship[person1][person2] = 1;
		relationship[person2][person1] = 1;
	}
}
init(M);

function findAnswer() {
	for (let i = 1; i <= N; ++i) {
		for (let j = 1; j <= N; ++j) {
			for (let x = 1; x <= N; ++x) {
				if (relationship[j][x] > relationship[j][i] + relationship[i][x])
					relationship[j][x] = relationship[j][i] + relationship[i][x];
			}
		}
	}
}

findAnswer();

let shortest = [Infinity, Infinity];
relationship.forEach((val, idx) => {
	if (idx === 0) return false;
	let tmp = 0;
	for (let i = 1; i <= N; ++i) {
		tmp += val[i];
	}
	shortest = shortest[0] > tmp ? [tmp, idx] : shortest;
});

console.log(shortest[1]);
