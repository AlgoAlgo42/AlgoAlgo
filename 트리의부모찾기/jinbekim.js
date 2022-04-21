const input = require('fs')
	.readFileSync('/dev/stdin')
	.toString()
	.trim()
	.split('\n');

const N = parseInt(input[0]);
const tree = { 1: [] };

for (let i = 1; i < N; ++i) {
	const [node1, node2] = input[i].split(' ').map(Number);
	tree[node1] ? tree[node1].push(node2) : (tree[node1] = [node2]);
	tree[node2] ? tree[node2].push(node1) : (tree[node2] = [node1]);
}
const parents = { 1: null };
function findParent(node) {
	tree[node].forEach((val) => {
		if (!parents[val]) parents[val] = node;
		else return false;
		findParent(val);
	});
}

findParent(1);
let result = parents[2];
for (let i = 3; i <= N; ++i) {
	result += '\n' + parents[i];
}
console.log(result);
