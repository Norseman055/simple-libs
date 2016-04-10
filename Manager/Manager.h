#pragma once

#include "Singleton.h"
#include "PCSTree\PCSTree.h"

template<typename T>
class NodeLink;

template<typename T>
class Manager : public Singleton<Manager<T>> {
	friend class Singleton<Manager<T>>;
protected:
	static void Add( NodeLink<T>* const node );
	static void Remove( NodeLink<T>* const node );
	static PCSTree* GetObjectList();
	static void Cleanup();

	Manager();
	virtual ~Manager();

private:
	// members
	PCSTree *active;
};

template <typename T>
void Manager<T>::Add( NodeLink<T>* const node ) {
	Manager<T>* man = GetInstance();

	NodeLink<T>* root = static_cast< NodeLink<T>* >(man->active->getRoot());
	man->active->insert( node, root );
}

template <typename T>
void Manager<T>::Remove( NodeLink<T>* const node ) {
	Manager<T>* man = GetInstance();

	man->active->remove( node );
}

template <typename T>
PCSTree* Manager<T>::GetObjectList() {
	return GetInstance()->active;
}

template <typename T>
void Manager<T>::Cleanup() {
	Manager<T>* man = GetInstance();
	if ( man->active->getRoot() ) {
		man->active->removeDown( man->active->getRoot() );
	}
}

template <typename T>
Manager<T>::Manager() {
	printf( "  Creating Manager...\n" );
	active = new PCSTree;

}

template <typename T>
Manager<T>::~Manager() {
	Cleanup();
	delete active;
}