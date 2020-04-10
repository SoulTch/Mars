#include <utility>

#include <core/hpp/model/Entity.hpp>

namespace MarsCore {

template<typename T, typename V>
Enchantment<T> *enchant(const std::string &detail, V &&enable) {
	class __enchant : public Enchantment<T> {
	public:
		__enchant(const std::string &detail, V&& content) : Enchantment<T>(detail), content(std::move(content)) { } 
		void enable(T *target) {
			content(target);
		}	
	private:
		const V content;
	};

	return new __enchant(detail, std::move(enable));
}

template<typename T, typename V>
Enchantment<T> *setEnchant(const std::string &detail, V val) {
	return enchant<T>(detail, [=](T *target) {
		*target = val;
	});
}





}