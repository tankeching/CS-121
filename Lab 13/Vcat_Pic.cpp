#include "Picture.h"
#include "Vcat_Pic.h"

Vcat_Pic::Vcat_Pic(const Picture& top, const Picture& bottom) : P_Node(), _top(top), _bottom(bottom){}
Picture operator&(const Picture& top, const Picture& bottom){
	return new Vcat_Pic(top._pnode, bottom._pnode);
}

int Vcat_Pic::height() const { return _top.height() + _bottom.height(); }
int Vcat_Pic::width() const { return max(_top.width(), _bottom.width()); }

void Vcat_Pic::display(ostream& os, int row, int wd) const{
	if (row >= 0 && row < _top.height()) { _top.display(os, row, wd); }
	else if (row < _top.height() + _bottom.height()) {
		_bottom.display(os, row - _top.height(), wd);
	}

	else{ pad(os, 0, wd); }
}

Picture Vcat_Pic::reframe(char c, char s, char t){
	return new Vcat_Pic(::reframe(_top, c, s, t), ::reframe(_bottom, c, s, t));
}

Picture* Vcat_Pic::getPic() { return &_top; }