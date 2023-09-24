#pragma once
using namespace System;

namespace PCL_CLI {

	template<class T>
	public ref class ManagedObject {
	protected:
		T* _instance;
	public:
		ManagedObject(T* instance)
			: _instance(instance) {}
		virtual ~ManagedObject() {
			if (_instance != nullptr) {
				delete _instance;
			}
		}
		!ManagedObject() {
			if (_instance != nullptr) {
				delete _instance;
			}
		}
		property T* Instance {
			T* get() {
				return _instance;
			}
			void set(T* value) {
				_instance = value;
			}
		}

		static void int_array_conversion(array<int>^ data) {
			pin_ptr<unsigned int> arrayPin = &data[0];
			unsigned int size = data->Length;
		}
	};
}