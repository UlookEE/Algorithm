#pragma once

int LSOne(int i) {
	return (i & (-i));	//return rightmost set bit
}