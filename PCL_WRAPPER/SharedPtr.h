//#pragma once
//
//#include <memory>
//#include "ManagedObject.h"
//
//namespace PCL_CLI {
//
//
//    template <class T>
//    public ref class SharedPtr sealed {
//        std::shared_ptr<T>* pPtr;
//
//    public:
//        SharedPtr()
//            : pPtr(new std::shared_ptr<T>()) {}
//
//        SharedPtr(T* t) {
//            pPtr = new std::shared_ptr<T>(t);
//        }
//
//        SharedPtr(std::shared_ptr<T> t) {
//            pPtr = new std::shared_ptr<T>(t);
//        }
//
//        SharedPtr(const SharedPtr<T>% t) {
//            pPtr = new std::shared_ptr<T>(*t.pPtr);
//        }
//
//        !SharedPtr() {
//            delete pPtr;
//        }
//
//        ~SharedPtr() {
//            delete pPtr;
//        }
//
//        operator std::shared_ptr<T>() {
//            return *pPtr;
//        }
//
//        SharedPtr<T>% operator=(T* ptr) {
//            delete pPtr;
//            pPtr = new std::shared_ptr<T>(ptr);
//            return *this;
//        }
//
//        T* operator->() {
//            return (*pPtr).get();
//        }
//
//        void reset() {
//            pPtr->reset();
//        }
//    };
//
//}