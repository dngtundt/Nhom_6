#include"PQueue.h"

int calculatePriority(const SinhVien* x) {
	int priority = 0;

	priority += (x->IsCntt ? 0 : 10000);

	priority += x->SoKhoa * 1000;

	priority += (x->IsGoodHeal ? 100 : 0);

	priority += x->CV * 10;

	priority += x->Tgian;

	return priority;
}