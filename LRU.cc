#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>


class LRUCache {
private:
	struct Node {
		int _key;
		int _val;
		Node(int key, int val) : _key(key), _val(val) {}
	};

	size_t _capacity;
	std::list<Node> _cacheList;
	std::unordered_map<int, std::list<Node>::iterator> _cacheMap;

public:
	LRUCache(int cap) : _capacity(cap) {}

	int getPage(int key) { // 访问某个页面
		if(_cacheMap.find(key) == _cacheMap.end()) {
			return -1; // 产生缺页中断
		}
		// 将key移动到第一个 更新_cacheMap
		_cacheList.splice(_cacheList.begin(), _cacheList, _cacheMap[key]);
		_cacheMap[key] = _cacheList.begin();
		return _cacheMap[key]->_val;
	}

	void setPage(int key, int val) {
		if(_cacheMap.find(key) == _cacheMap.end()) {
			// 淘汰最后一个
			if(_cacheList.size() == _capacity) {
				_cacheMap.erase(_cacheList.back()._key);
				_cacheList.pop_back();
			}
			_cacheList.push_front(Node(key, val));
			_cacheMap[key] = _cacheList.begin();
		} else{
			// 更新结点即可
			_cacheMap[key]->_val = val;
			_cacheList.splice(_cacheList.begin(), _cacheList, _cacheMap[key]);
			_cacheMap[key] = _cacheList.begin();
		}
	}
};
