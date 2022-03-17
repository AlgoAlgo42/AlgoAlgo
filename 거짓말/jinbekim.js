const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
const [n, m] = input[0].split(' ').map(Number);
const [_, ...whoKnowTruth] = input[1].split(' ').map(Number);

const parent = new Array(n + 1);
const party = new Array(m);
const rank = new Array(n + 1).fill(0);

function find(a) {
	if (parent[a] === a) return a;
	return (parent[a] = find(parent[a]));
}

function union(a, b) {
	const rootA = find(a);
	const rootB = find(b);
	if (rootA === rootB) return;
	if (rank[rootA] > rank[rootB]) {
		parent[rootB] = rootA;
	} else {
		parent[rootA] = rootB;
		if (rank[rootA] === rank[rootB]) rank[rootB]++;
	}
}

if (whoKnowTruth === 0) console.log(m);
else {
	for (let i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (let i = 0; i < m; i++) {
		const [num, ...person] = input[i + 2].split(' ').map(Number);
		party[i] = person;
		for (let j = 0; j < num - 1; j++) {
			union(person[j], person[j + 1]);
		}
	}
	let answer = m;
	for (let i = 0; i < m; i++) {
		for (who of whoKnowTruth) {
			if (find(who) === find(party[i][0])) {
				answer--;
				break;
			}
		}
	}
	console.log(answer);
}
