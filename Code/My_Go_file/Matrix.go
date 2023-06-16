package main

import "fmt"

const mod int64 = 1e9 + 7

var n, p, m int

const N = 505

var A, B, ans [N][N]int64

func main() {
	fmt.Scanf("%d %d %d\n", &n, &p, &m)
	//fmt.Print("%d", n)
	for i := 0; i < n; i++ {
		for j := 0; j < p; j++ {
			fmt.Scanf("%d", &A[i][j])
		}
		fmt.Scanf("\n")
	}
	for i := 0; i < p; i++ {
		for j := 0; j < m; j++ {
			fmt.Scanf("%d", &B[i][j])
		}
		fmt.Scanf("\n")
	}
	ans = Matrix(A, B)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			fmt.Printf("%d ", ans[i][j])
		}
		fmt.Printf("\n")
	}
}

func Matrix(x [N][N]int64, y [N][N]int64) (a [N][N]int64) {
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			for k := 0; k < p; k++ {
				a[i][j] = (mod + a[i][j] + (x[i][k]*y[k][j])%mod) % mod
			}
		}
	}
	return
}
