#ifndef _IMMUTBAG_H
#define _IMMUTBAG_H

#include <cstddef>

namespace artemis {
		template<typename E>
		class ImmutableBag {
			public:
				virtual E get(int index) = 0;
				virtual int getCapacity() = 0;
				virtual int getCount() = 0;
				virtual bool isEmpty() = 0;
		};

		template<typename E>
		class Bag : public ImmutableBag<E> {


			public:
				Bag() {
					init(64);
				};


				Bag(int capacity) {
					init(capacity);
				};

				void add(E o) {
					if(size == count)grow();

					data[count++] = o;
				};

				void addAll(Bag<E> & bag) {

					for(int i=0; i < bag.size ; i++) {
						addItem(bag.data[i]);
					}
				};

				void clear() {
					for(int i=0; i<size; i++) {
						data[i] = nullptr;
					}

					count = 0;

				};

				bool contains(E o) {

					for(int i=0; i<count; i++)
						if(o == data[i])
							return true;

					return false;
				};

				virtual E get(int index) {
					return (E)data[index];
				};

				virtual int getCapacity() {return size;};
				virtual bool isEmpty() {return count == 0;};
				virtual int getCount() {return count;};

				bool remove(E o) {

					for(int i=0; i<count; i++) {
						if(o == data[i]) {
							remove(i);
							return true;
						}
					}

					return false;
				};

				E remove(int index) {
					if(count == 0) return nullptr;

					E object = data[index];
					data[index] = data[count-1];
					data[count-1] = nullptr;
					count--;
					return (E) object;
				};

				bool removeAll(Bag<E> bag) {
					bool mod = false;

					for(int i=0; i<bag.count; i++)
						for(int j= 0; j< count ; j++)
							if(bag.data[i] == data[j]) {
								remove(j);
								j--; // ?
								mod = true;
								break;
							}

					return mod;

				};


				E removeLast() {
					if(!isEmpty()) {
						E object = data[count-1];
						data[count-1] = nullptr;
						return (E) object;
					}

					return nullptr;
				};


				bool set(int index, E o) {
					if(index > size) grow(index*2);;

					data[index] = o;
					return true;
				};


				void operator += (Bag<E> &bag) {
					addAll(bag);
				};


				~Bag<E>() {


				};


			private:

				int count;
				int size;
				E *data;

				void grow() {
					int newCapacity =(size * 3.0f) * 0.5f + 1.0f;
					grow(newCapacity);
				};

				void grow(int newCapacity) {

					E * currentData = data;
					data = new E[newCapacity];
					size = newCapacity;

					for(int i=0; i < count; i++) {
						data[i] = currentData[i];
					}
				};

				void init(int capacity) {
					size = capacity;
					count = 0;
					data = new E[capacity];
					clear();
				}

		};
};

#endif // $(Guard token)
