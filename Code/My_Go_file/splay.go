package main

// type Splay_Tree_Node,0 left,1 right
type stn struct {
	father     *stn
	son        [2]*stn
	repitition int
	value      int
	size       int
}

type Root struct {
	root stn
}

func (this *stn) update(){
	if this.son[0] != nil{
		if this.son[1] != nil {
			this.size = this.repitition + this.son[0].size + this.son[1].size
		} else {
			this.size = this.repitition + this.son[0].size
		}
	} else {
		if this.son[1] != nil {
			this.size = this.repitition + this.son[1].size
		} else {
			this.size = this.repitition
		}
	}
}