/*
 * EIoFilterChainBuilder.hh
 *
 *  Created on: 2017-3-16
 *      Author: cxxjava@163.com
 */

#ifndef NFILTERCHAINBUILDER_HH_
#define NFILTERCHAINBUILDER_HH_

#include "./EIoFilterChain.hh"

namespace efc {
namespace naf {

/**
 * The default implementation of {@link IoFilterChainBuilder} which is useful
 * in most cases.  {@link DefaultIoFilterChainBuilder} has an identical interface
 * with {@link IoFilter}; it contains a list of {@link IoFilter}s that you can
 * modify. The {@link IoFilter}s which are added to this builder will be appended
 * to the {@link IoFilterChain} when {@link #buildFilterChain(IoFilterChain)} is
 * invoked.
 * <p>
 * However, the identical interface doesn't mean that it behaves in an exactly
 * same way with {@link IoFilterChain}.  {@link DefaultIoFilterChainBuilder}
 * doesn't manage the life cycle of the {@link IoFilter}s at all, and the
 * existing {@link IoSession}s won't get affected by the changes in this builder.
 * {@link IoFilterChainBuilder}s affect only newly created {@link IoSession}s.
 *
 * <pre>
 * IoAcceptor acceptor = ...;
 * DefaultIoFilterChainBuilder builder = acceptor.getFilterChain();
 * builder.addLast( "myFilter", new MyFilter() );
 * ...
 * </pre>
 *
 */

class EIoFilterChainBuilder: public EObject {
public:
	virtual ~EIoFilterChainBuilder();

	/**
	 * Creates a new instance with an empty filter list.
	 */
	EIoFilterChainBuilder();

	/**
	 * Returns the {@link Entry} with the specified <tt>name</tt> in this chain.
	 *
	 * @param name The filter's name we are looking for
	 * @return <tt>null</tt> if there's no such name in this chain
	 */
	EIoFilterChain::Entry* getEntry(const char* name);

	/**
	 * @see IoFilterChain#getEntry(IoFilter)
	 *
	 * @param filter The Filter we are looking for
	 * @return The found Entry
	 */
	EIoFilterChain::Entry* getEntry(EIoFilter* filter);

	/**
	 * @see IoFilterChain#get(String)
	 *
	 * @param name The Filter's name we are looking for
	 * @return The found Filter, or null
	 */
	EIoFilter* get(const char* name);

	/**
	 * @see IoFilterChain#contains(String)
	 *
	 * @param name The Filter's name we want to check if it's in the chain
	 * @return <tt>true</tt> if the chain contains the given filter name
	 */
	boolean contains(const char* name);

	/**
	 * @see IoFilterChain#contains(IoFilter)
	 *
	 * @param filter The Filter we want to check if it's in the chain
	 * @return <tt>true</tt> if the chain contains the given filter
	 */
	boolean contains(EIoFilter* filter);

	/**
	 * @see IoFilterChain#addFirst(String, IoFilter)
	 *
	 * @param name The filter's name
	 * @param filter The filter to add
	 */
	void addFirst(const char* name, EIoFilter* filter);

	/**
	 * @see IoFilterChain#addLast(String, IoFilter)
	 *
	 * @param name The filter's name
	 * @param filter The filter to add
	 */
	void addLast(const char* name, EIoFilter* filter);

	/**
	 * @see IoFilterChain#addBefore(String, String, IoFilter)
	 *
	 * @param baseName The filter baseName
	 * @param name The filter's name
	 * @param filter The filter to add
	 */
	void addBefore(const char* baseName, const char* name, EIoFilter* filter);

	/**
	 * @see IoFilterChain#addAfter(String, String, IoFilter)
	 *
	 * @param baseName The filter baseName
	 * @param name The filter's name
	 * @param filter The filter to add
	 */
	void addAfter(const char* baseName, const char* name, EIoFilter* filter);

	/**
	 * @see IoFilterChain#remove(String)
	 *
	 * @param name The Filter's name to remove from the list of Filters
	 * @return The removed IoFilter
	 */
	EIoFilter* remove(const char* name);

	/**
	 * @see IoFilterChain#remove(IoFilter)
	 *
	 * @param filter The Filter we want to remove from the list of Filters
	 * @return The removed IoFilter
	 */
	EIoFilter* remove(EIoFilter* filter);

	/**
	 * @see IoFilterChain#clear()
	 */
	void clear();

	/**
	 * @see IoFilterChain#buildFilterChain(IoFilterChain)
	 */
	void buildFilterChain(EIoFilterChain* chain) THROWS(EException);

	/**
	 *
	 */
	virtual EString toString();

private:
	ECopyOnWriteArrayList<EIoFilterChain::Entry> entries;

	void register_(int index, EIoFilterChain::Entry* e);
	void checkBaseName(const char* baseName);
};

} /* namespace naf */
} /* namespace efc */
#endif /* NFILTERCHAINBUILDER_HH_ */
