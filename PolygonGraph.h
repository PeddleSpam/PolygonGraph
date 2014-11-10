#ifndef POLYGON_GRAPH_H
#define POLYGON_GRAPH_H

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// INCLUDES +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <list>
#include <set>

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// GRAPH NAMESPACE ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

namespace graph
{
    // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // DEFAULT POLYGON GRAPH TRAITS CLASS +++++++++++++++++++++++++++++++++++++
    // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    class DefaultPGTraits
    {
        public:

        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        // PUBLIC TYPES +++++++++++++++++++++++++++++++++++++++++++++++++++++++
        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        // BASE VERTEX CLASS --------------------------------------------------

        class BaseVertex {};

        // BASE EDGE CLASS ----------------------------------------------------

        class BaseEdge {};

        // BASE POLYGON CLASS -------------------------------------------------

        class BasePolygon {};

        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    };
    
    // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // POLYGON GRAPH CLASS ++++++++++++++++++++++++++++++++++++++++++++++++++++
    // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    template< class Traits = DefaultPGTraits >
    class PolygonGraph
    {
        public:

        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        // PUBLIC TYPES +++++++++++++++++++++++++++++++++++++++++++++++++++++++
        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        // SIZE TYPE ----------------------------------------------------------

        typedef std::size_t size_type;

        // BASE PRIMITIVES ----------------------------------------------------

        typedef typename Traits::BaseVertex BaseVertex;
        typedef typename Traits::BaseEdge BaseEdge;
        typedef typename Traits::BasePolygon BasePolygon;

        // PRIMITIVES ---------------------------------------------------------

        class Vertex;
        class Edge;
        class Polygon;

        // VERTEX ITERATOR CLASS ----------------------------------------------

        class ConstVertexIterator; // forward declaration

        class VertexIterator : public std::bidirectional_iterator_tag
        {
            public:

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // FRIENDS ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            friend class Vertex;
            friend class ConstVertexIterator;
            friend class PolygonGraph< Traits >;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC TYPES +++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            typedef typename std::list< Vertex >::iterator VertexListIterator;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC METHODS +++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // CONSTRUCTORS ---------------------------------------------------

            VertexIterator( void )
            {
                // empty
            }

            VertexIterator( VertexListIterator iter )
            {
                this->iter = iter;
            }

            // COPY CONSTRUCTOR -----------------------------------------------

            VertexIterator( VertexIterator const & other )
            {
                this->iter = other.iter;
            }

            // MOVE CONSTRUCTOR -----------------------------------------------

            VertexIterator( VertexIterator && other )
            {
                this->iter = other.iter;
            }

            // DESTRUCTOR -----------------------------------------------------

            ~VertexIterator( void )
            {
                // empty
            }

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC OPERATORS +++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // COPY ASSIGNMENT ------------------------------------------------

            VertexIterator const & operator = ( VertexIterator const & other )
            {
                this->iter = other.iter;

                return *this;
            }

            // MOVE ASSIGNMENT ------------------------------------------------

            VertexIterator const & operator = ( VertexIterator && other )
            {
                this->iter = other.iter;

                return *this;
            }

            // EQUALITY -------------------------------------------------------

            bool const operator == ( VertexIterator const & other ) const
            {
                return this->iter == other.iter;
            }

            bool const operator == ( ConstVertexIterator const & other ) const
            {
                return this->iter == other.iter;
            }

            // INEQUALITY -----------------------------------------------------

            bool const operator != ( VertexIterator const & other ) const
            {
                return this->iter != other.iter;
            }

            bool const operator != ( ConstVertexIterator const & other ) const
            {
                return this->iter != other.iter;
            }

            // INDIRECTION ----------------------------------------------------

            Vertex & operator * ( void ) const
            {
                return *iter;
            }

            // STRUCTURE DEREFERENCE ------------------------------------------

            Vertex * operator -> ( void ) const
            {
                return &( *iter );
            }

            // INCREMENT ------------------------------------------------------

            VertexIterator const & operator ++ ( void ) // prefix
            {
                ++iter;
                return *this;
            }

            VertexIterator const operator ++ ( int ) // postfix
            {
                VertexIterator copy( *this );
                ++iter;
                return copy;
            }

            // DECREMENT ------------------------------------------------------

            VertexIterator const & operator -- ( void ) // prefix
            {
                --iter;
                return *this;
            }

            VertexIterator const operator -- ( int ) // postfix
            {
                VertexIterator copy( *this );
                --iter;
                return copy;
            }

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            private:

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PRIVATE DATA +++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            VertexListIterator iter;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        };

        class ConstVertexIterator : public std::bidirectional_iterator_tag
        {
            public:

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // FRIENDS ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            friend class Vertex;
            friend class VertexIterator;
            friend class PolygonGraph< Traits >;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC TYPES +++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            typedef typename std::list< Vertex >::iterator VertexListIterator;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC METHODS +++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // CONSTRUCTORS ---------------------------------------------------

            ConstVertexIterator( void )
            {
                // empty
            }

            ConstVertexIterator( VertexListIterator iter )
            {
                this->iter = iter;
            }

            // COPY CONSTRUCTOR -----------------------------------------------

            ConstVertexIterator( ConstVertexIterator const & other )
            {
                this->iter = other.iter;
            }

            ConstVertexIterator( VertexIterator const & other )
            {
                this->iter = other.iter;
            }

            // MOVE CONSTRUCTOR -----------------------------------------------

            ConstVertexIterator( ConstVertexIterator && other )
            {
                this->iter = other.iter;
            }

            ConstVertexIterator( VertexIterator && other )
            {
                this->iter = other.iter;
            }

            // DESTRUCTOR -----------------------------------------------------

            ~ConstVertexIterator( void )
            {
                // empty
            }

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC OPERATORS +++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // COPY ASSIGNMENT ------------------------------------------------

            ConstVertexIterator const & operator =
                ( ConstVertexIterator const & other )
            {
                this->iter = other.iter;
                return *this;
            }

            ConstVertexIterator const & operator =
                ( VertexIterator const & other )
            {
                this->iter = other.iter;
                return *this;
            }

            // MOVE ASSIGNMENT ------------------------------------------------

            ConstVertexIterator const & operator =
                ( ConstVertexIterator && other )
            {
                this->iter = other.iter;
                return *this;
            }

            ConstVertexIterator const & operator = ( VertexIterator && other )
            {
                this->iter = other.iter;
                return *this;
            }

            // EQUALITY -------------------------------------------------------

            bool const operator == ( ConstVertexIterator const & other ) const
            {
                return this->iter == other.iter;
            }

            bool const operator == ( VertexIterator const & other ) const
            {
                return this->iter == other.iter;
            }

            // INEQUALITY -----------------------------------------------------

            bool const operator != ( ConstVertexIterator const & other ) const
            {
                return this->iter != other.iter;
            }

            bool const operator != ( VertexIterator const & other ) const
            {
                return this->iter != other.iter;
            }

            // INDIRECTION ----------------------------------------------------

            Vertex const & operator * ( void ) const
            {
                return *iter;
            }

            // STRUCTURE DEREFERENCE ------------------------------------------

            Vertex const * operator -> ( void ) const
            {
                return &( *iter );
            }

            // INCREMENT ------------------------------------------------------

            ConstVertexIterator const & operator ++ ( void ) // prefix
            {
                ++iter;
                return *this;
            }

            ConstVertexIterator const operator ++ ( int ) // postfix
            {
                ConstVertexIterator copy( *this );
                ++iter;
                return copy;
            }

            // DECREMENT ------------------------------------------------------

            ConstVertexIterator const & operator -- ( void ) // prefix
            {
                --iter;
                return *this;
            }

            ConstVertexIterator const operator -- ( int ) // postfix
            {
                ConstVertexIterator copy( *this );
                --iter;
                return copy;
            }

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            private:

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PRIVATE DATA +++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            VertexListIterator iter;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        };

        // POLYGON ITERATOR CLASS ---------------------------------------------

        class ConstPolygonIterator; // forward declaration

        class PolygonIterator : public std::bidirectional_iterator_tag
        {
            public:

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // FRIENDS ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            friend class ConstPolygonIterator;
            friend class PolygonGraph< Traits >;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC TYPES +++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            typedef typename std::list< Polygon >::iterator
                PolygonListIterator;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC METHODS +++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // CONSTRUCTORS ---------------------------------------------------

            PolygonIterator( void )
            {
                // empty
            }

            PolygonIterator( PolygonListIterator iter )
            {
                this->iter = iter;
            }

            // COPY CONSTRUCTOR -----------------------------------------------

            PolygonIterator( PolygonIterator const & other )
            {
                this->iter = other.iter;
            }

            // MOVE CONSTRUCTOR -----------------------------------------------

            PolygonIterator( PolygonIterator && other )
            {
                this->iter = other.iter;
            }

            // DESTRUCTOR -----------------------------------------------------

            ~PolygonIterator( void )
            {
                // empty
            }

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC OPERATORS +++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // COPY ASSIGNMENT ------------------------------------------------

            PolygonIterator const & operator =
                ( PolygonIterator const & other )
            {
                this->iter = other.iter;
                return *this;
            }

            // MOVE ASSIGNMENT ------------------------------------------------

            PolygonIterator const & operator =
                ( PolygonIterator && other )
            {
                this->iter = other.iter;
                return *this;
            }

            // EQUALITY -------------------------------------------------------

            bool const operator == ( PolygonIterator const & other ) const
            {
                return this->iter == other.iter;
            }

            bool const operator == ( ConstPolygonIterator const & other ) const
            {
                return this->iter == other.iter;
            }

            // INEQUALITY -----------------------------------------------------

            bool const operator != ( PolygonIterator const & other ) const
            {
                return this->iter != other.iter;
            }

            bool const operator != ( ConstPolygonIterator const & other ) const
            {
                return this->iter != other.iter;
            }

            // INDIRECTION ----------------------------------------------------

            Polygon & operator * ( void ) const
            {
                return *iter;
            }

            // STRUCTURE DEREFERENCE ------------------------------------------

            Polygon * operator -> ( void ) const
            {
                return &( *iter );
            }

            // INCREMENT ------------------------------------------------------

            PolygonIterator const & operator ++ ( void ) // prefix
            {
                ++iter;
                return *this;
            }

            PolygonIterator const operator ++ ( int ) // postfix
            {
                PolygonIterator copy( *this );
                ++iter;
                return copy;
            }

            // DECREMENT ------------------------------------------------------

            PolygonIterator const & operator -- ( void ) // prefix
            {
                --iter;
                return *this;
            }

            PolygonIterator const operator -- ( int ) // postfix
            {
                PolygonIterator copy( *this );
                --iter;
                return copy;
            }

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            private:

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PRIVATE DATA +++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            PolygonListIterator iter;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        };

        class ConstPolygonIterator : public std::bidirectional_iterator_tag
        {
            public:

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // FRIENDS ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            friend class PolygonIterator;
            friend class PolygonGraph< Traits >;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC TYPES +++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            typedef typename std::list< Polygon >::iterator
                PolygonListIterator;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC METHODS +++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // CONSTRUCTORS ---------------------------------------------------

            ConstPolygonIterator( void )
            {
                // empty
            }

            ConstPolygonIterator( PolygonListIterator iter )
            {
                this->iter = iter;
            }

            // COPY CONSTRUCTOR -----------------------------------------------

            ConstPolygonIterator( ConstPolygonIterator const & other )
            {
                this->iter = other.iter;
            }

            ConstPolygonIterator( PolygonIterator const & other )
            {
                this->iter = other.iter;
            }

            // MOVE CONSTRUCTOR -----------------------------------------------

            ConstPolygonIterator( ConstPolygonIterator && other )
            {
                this->iter = other.iter;
            }

            ConstPolygonIterator( PolygonIterator && other )
            {
                this->iter = other.iter;
            }

            // DESTRUCTOR -----------------------------------------------------

            ~ConstPolygonIterator( void )
            {
                // empty
            }

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC OPERATORS +++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // COPY ASSIGNMENT ------------------------------------------------

            ConstPolygonIterator const & operator =
                ( ConstPolygonIterator const & other )
            {
                this->iter = other.iter;
                return *this;
            }

            ConstPolygonIterator const & operator =
                ( PolygonIterator const & other )
            {
                this->iter = other.iter;
                return *this;
            }

            // MOVE ASSIGNMENT ------------------------------------------------

            ConstPolygonIterator const & operator =
                ( ConstPolygonIterator && other )
            {
                this->iter = other.iter;
                return *this;
            }

            ConstPolygonIterator const & operator =
                ( PolygonIterator && other )
            {
                this->iter = other.iter;
                return *this;
            }

            // EQUALITY -------------------------------------------------------

            bool const operator == ( ConstPolygonIterator const & other ) const
            {
                return this->iter == other.iter;
            }

            bool const operator == ( PolygonIterator const & other ) const
            {
                return this->iter == other.iter;
            }

            // INEQUALITY -----------------------------------------------------

            bool const operator != ( ConstPolygonIterator const & other ) const
            {
                return this->iter != other.iter;
            }

            bool const operator != ( PolygonIterator const & other ) const
            {
                return this->iter != other.iter;
            }

            // INDIRECTION ----------------------------------------------------

            Polygon const & operator * ( void ) const
            {
                return *iter;
            }

            // STRUCTURE DEREFERENCE ------------------------------------------

            Polygon const * operator -> ( void ) const
            {
                return &( *iter );
            }

            // INCREMENT ------------------------------------------------------

            ConstPolygonIterator const & operator ++ ( void ) // prefix
            {
                ++iter;
                return *this;
            }

            ConstPolygonIterator const operator ++ ( int ) // postfix
            {
                ConstPolygonIterator copy( *this );
                ++iter;
                return copy;
            }

            // DECREMENT ------------------------------------------------------

            ConstPolygonIterator const & operator -- ( void ) // prefix
            {
                --iter;
                return *this;
            }

            ConstPolygonIterator const operator -- ( int ) // postfix
            {
                ConstPolygonIterator copy( *this );
                --iter;
                return copy;
            }

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            private:

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PRIVATE DATA +++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            PolygonListIterator iter;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        };

        // VERTEX CLASS -------------------------------------------------------

        class Vertex : public BaseVertex
        {
            private:

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PRIVATE TYPES ++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // EDGE SET LESS FUNCTOR ------------------------------------------

            class EdgeSetLess
            {
                public:

                bool const operator () ( Edge * const & lhs,
                                         Edge * const & rhs ) const
                {
                    return &( *( lhs->getTargetVertex() ) ) <
                           &( *( rhs->getTargetVertex() ) );
                }
            };

            // EDGE SET -------------------------------------------------------

            typedef std::multiset< Edge *, EdgeSetLess > EdgeSet;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            public:

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // FRIENDS ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            friend class PolygonGraph< Traits >;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC TYPES +++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // ITERATORS ------------------------------------------------------

            class ConstEdgeIterator; // forward declaration

            class EdgeIterator : public std::forward_iterator_tag
            {
                public:

                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                // FRIENDS ++++++++++++++++++++++++++++++++++++++++++++++++++++
                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

                friend class Vertex;
                friend class ConstEdgeIterator;

                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                // PUBLIC METHODS +++++++++++++++++++++++++++++++++++++++++++++
                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

                // CONSTRUCTORS -----------------------------------------------

                EdgeIterator( void )
                {
                    // empty
                }

                EdgeIterator( typename EdgeSet::const_iterator const & iter )
                {
                    this->iter = iter;
                }

                // COPY CONSTRUCTOR -------------------------------------------

                EdgeIterator( EdgeIterator const & other )
                {
                    this->iter = other.iter;
                }

                // MOVE CONSTRUCTOR -------------------------------------------

                EdgeIterator( EdgeIterator && other )
                {
                    this->iter = other.iter;
                }

                // DESTRUCTOR -------------------------------------------------

                ~EdgeIterator( void )
                {
                    // empty
                }

                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                // PUBLIC OPERATORS +++++++++++++++++++++++++++++++++++++++++++
                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

                // COPY ASSIGNMENT --------------------------------------------

                EdgeIterator const & operator = ( EdgeIterator const & other )
                {
                    this->iter = other.iter;

                    return *this;
                }

                // MOVE ASSIGNMENT --------------------------------------------

                EdgeIterator const & operator = ( EdgeIterator && other )
                {
                    this->iter = other.iter;

                    return *this;
                }

                // EQUALITY ---------------------------------------------------

                bool const operator == ( EdgeIterator const & other ) const
                {
                    //return &( *( this->iter ) ) == &( *( other.iter ) );
                    return this->iter == other.iter;
                }

                bool const operator ==
                    ( ConstEdgeIterator const & other ) const
                {
                    //return &( *( this->iter ) ) == &( *( other.iter ) );
                    return this->iter == other.iter;
                }

                // INEQUALITY -------------------------------------------------

                bool const operator != ( EdgeIterator const & other ) const
                {
                    //return &( *( this->iter ) ) != &( *( other.iter ) );
                    return this->iter != other.iter;
                }

                bool const operator !=
                    ( ConstEdgeIterator const & other ) const
                {
                    //return &( *( this->iter ) ) != &( *( other.iter ) );
                    return this->iter != other.iter;
                }

                // INDIRECTION ------------------------------------------------

                Edge & operator * ( void ) const
                {
                    return **iter;
                }

                // STRUCTURE DEREFERENCE --------------------------------------

                Edge * operator -> ( void ) const
                {
                    return *iter;
                }

                // INCREMENT --------------------------------------------------

                EdgeIterator const & operator ++ ( void ) // prefix
                {
                    ++iter;

                    return *this;
                }

                EdgeIterator const operator ++ ( int ) // postfix
                {
                    EdgeIterator copy( *this );

                    ++iter;

                    return copy;
                }

                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

                private:

                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                // PRIVATE DATA +++++++++++++++++++++++++++++++++++++++++++++++
                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

                typename EdgeSet::const_iterator iter;

                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            };

            class ConstEdgeIterator : public std::forward_iterator_tag
            {
                public:

                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                // FRIENDS ++++++++++++++++++++++++++++++++++++++++++++++++++++
                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

                friend class Vertex;
                friend class EdgeIterator;

                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                // PUBLIC METHODS +++++++++++++++++++++++++++++++++++++++++++++
                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

                // CONSTRUCTORS -----------------------------------------------

                ConstEdgeIterator( void )
                {
                    // empty
                }

                ConstEdgeIterator
                    ( typename EdgeSet::const_iterator const & iter )
                {
                    this->iter = iter;
                }

                // COPY CONSTRUCTOR -------------------------------------------

                ConstEdgeIterator( ConstEdgeIterator const & other )
                {
                    this->iter = other.iter;
                }

                ConstEdgeIterator( EdgeIterator const & other )
                {
                    this->iter = other.iter;
                }

                // MOVE CONSTRUCTOR -------------------------------------------

                ConstEdgeIterator( ConstEdgeIterator && other )
                {
                    this->iter = other.iter;
                }

                ConstEdgeIterator( EdgeIterator && other )
                {
                    this->iter = other.iter;
                }

                // DESTRUCTOR -------------------------------------------------

                ~ConstEdgeIterator( void )
                {
                    // empty
                }

                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                // PUBLIC OPERATORS +++++++++++++++++++++++++++++++++++++++++++
                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

                // COPY ASSIGNMENT --------------------------------------------

                ConstEdgeIterator const & operator =
                    ( ConstEdgeIterator const & other )
                {
                    this->iter = other.iter;

                    return *this;
                }

                ConstEdgeIterator const & operator =
                    ( EdgeIterator const & other )
                {
                    this->iter = other.iter;

                    return *this;
                }

                // MOVE ASSIGNMENT --------------------------------------------

                ConstEdgeIterator const & operator =
                    ( ConstEdgeIterator && other )
                {
                    this->iter = other.iter;

                    return *this;
                }

                ConstEdgeIterator const & operator =
                    ( EdgeIterator && other )
                {
                    this->iter = other.iter;

                    return *this;
                }

                // EQUALITY ---------------------------------------------------

                bool const operator ==
                    ( ConstEdgeIterator const & other ) const
                {
                    return this->iter == other.iter;
                }

                bool const operator ==
                    ( EdgeIterator const & other ) const
                {
                    return this->iter == other.iter;
                }

                // INEQUALITY -------------------------------------------------

                bool const operator !=
                    ( ConstEdgeIterator const & other ) const
                {
                    return this->iter != other.iter;
                }

                bool const operator !=
                    ( EdgeIterator const & other ) const
                {
                    return this->iter != other.iter;
                }

                // INDIRECTION ------------------------------------------------

                Edge const & operator * ( void ) const
                {
                    return **iter;
                }

                // STRUCTURE DEREFERENCE --------------------------------------

                Edge const * operator -> ( void ) const
                {
                    return *iter;
                }

                // INCREMENT --------------------------------------------------

                ConstEdgeIterator const & operator ++ ( void ) // prefix
                {
                    ++iter;

                    return *this;
                }

                ConstEdgeIterator const & operator ++ ( int ) // postfix
                {
                    ConstEdgeIterator copy( *this );

                    ++iter;

                    return copy;
                }

                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

                private:

                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                // PRIVATE DATA +++++++++++++++++++++++++++++++++++++++++++++++
                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

                typename EdgeSet::const_iterator iter;

                // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            };

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC METHODS +++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // CONSTRUCTORS ---------------------------------------------------

            Vertex( void ) : BaseVertex()
            {
                // empty
            }

            // COPY CONSTRUCTOR -----------------------------------------------

            Vertex( Vertex const & other ) : BaseVertex( other )
            {
                this->edges = other.edges;
            }

            // MOVE CONSTRUCTOR -----------------------------------------------

            Vertex( Vertex && other ) : BaseVertex( other )
            {
                this->edges = other.edges;
            }

            // DESTRUCTOR -----------------------------------------------------

            ~Vertex( void )
            {
                // empty
            }

            // BEGIN EDGES ----------------------------------------------------

            EdgeIterator beginEdges( void )
            {
                return EdgeIterator( edges.begin() );
            }

            ConstEdgeIterator cbeginEdges( void ) const
            {
                return ConstEdgeIterator( edges.begin() );
            }

            // END EDGES ------------------------------------------------------

            EdgeIterator endEdges( void )
            {
                return EdgeIterator( edges.end() );
            }

            ConstEdgeIterator cendEdges( void ) const
            {
                return ConstEdgeIterator( edges.end() );
            }

            // FIND EDGES -----------------------------------------------------

            std::pair< EdgeIterator, EdgeIterator >
                findEdges( VertexIterator iter )
            {
                // Construct edge to search for

                Edge edge;
                edge.setTargetVertex( iter );

                // Search for matching edges

                std::pair< typename EdgeSet::const_iterator,
                           typename EdgeSet::const_iterator > pair =
                    edges.equal_range( &edge );

                // Return pair of iterators to range

                return std::pair< EdgeIterator, EdgeIterator >
                (
                    EdgeIterator( pair.first ),
                    EdgeIterator( pair.second )
                );
            }

            std::pair< ConstEdgeIterator, ConstEdgeIterator >
                findEdges( ConstVertexIterator iter ) const
            {
                // Construct edge to search for
                
                Edge edge;
                edge.setTargetVertex( VertexIterator( iter.iter ) );

                // Search for matching edges

                std::pair< typename EdgeSet::const_iterator,
                           typename EdgeSet::const_iterator > pair =
                    edges.equal_range( &edge );
                
                // Return pair of iterators to range

                return std::pair< ConstEdgeIterator, ConstEdgeIterator >
                (
                    ConstEdgeIterator( pair.first ),
                    ConstEdgeIterator( pair.second )
                );
            }

            // GET EDGE COUNT -------------------------------------------------

            size_type const getEdgeCount( void ) const
            {
                return edges.size();
            }

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC OPERATORS +++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // COPY ASSIGNMENT ------------------------------------------------

            Vertex const & operator = ( Vertex const & other )
            {
                BaseVertex::operator=( other );

                this->edges = other.edges;

                return *this;
            }

            // MOVE ASSIGNMENT ------------------------------------------------

            Vertex const & operator = ( Vertex && other )
            {
                BaseVertex::operator=( other );

                this->edges = other.edges;

                return *this;
            }

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            private:

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PRIVATE METHODS ++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // ADD EDGE -------------------------------------------------------

            EdgeIterator addEdge( Edge * edge )
            {
                return EdgeIterator( edges.insert( edge ) );
            }

            // REMOVE EDGE ----------------------------------------------------

            EdgeIterator removeEdge( EdgeIterator position )
            {
                return EdgeIterator( edges.erase( position.iter ) );
            }

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PRIVATE DATA +++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            EdgeSet edges;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        };

        // EDGE CLASS ---------------------------------------------------------

        class Edge : public BaseEdge
        {
            public:

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // FRIENDS ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            friend class Vertex;
            friend class PolygonGraph< Traits >;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC TYPES +++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // ITERATORS ------------------------------------------------------

            typedef typename Vertex::EdgeIterator        EdgeIterator;
            typedef typename Vertex::ConstEdgeIterator    ConstEdgeIterator;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC METHODS +++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // CONSTRUCTORS ---------------------------------------------------

            Edge( void ) : BaseEdge()
            {
                // empty
            }

            // COPY CONSTRUCTOR -----------------------------------------------

            Edge( Edge const & other ) : BaseEdge( other )
            {
                this->targetVertex    = other.targetVertex;
                this->nextEdge        = other.nextEdge;
                this->previousEdge    = other.previousEdge;
                this->polygon        = other.polygon;
            }

            // MOVE CONSTRUCTOR -----------------------------------------------

            Edge( Edge && other ) : BaseEdge( other )
            {
                this->targetVertex    = other.targetVertex;
                this->nextEdge        = other.nextEdge;
                this->previousEdge    = other.previousEdge;
                this->polygon        = other.polygon;
            }

            // DESTRUCTOR -----------------------------------------------------

            ~Edge( void )
            {
                // empty
            }

            // GET TARGET VERTEX ----------------------------------------------

            VertexIterator getTargetVertex( void )
            {
                return targetVertex;
            }

            ConstVertexIterator getTargetVertex( void ) const
            {
                return targetVertex;
            }

            // GET NEXT EDGE --------------------------------------------------

            Edge * getNextEdge( void )
            {
                return &( *nextEdge );
            }

            Edge const * getNextEdge( void ) const
            {
                return &( *nextEdge );
            }

            // GET PREVIOUS EDGE ----------------------------------------------

            Edge * getPreviousEdge( void )
            {
                return &( *previousEdge );
            }

            Edge const * getPreviousEdge( void ) const
            {
                return &( *previousEdge );
            }

            // GET POLYGON ----------------------------------------------------

            PolygonIterator getPolygon( void )
            {
                return polygon;
            }

            ConstPolygonIterator getPolygon( void ) const
            {
                return polygon;
            }

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC OPERATORS +++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // COPY ASSIGNMENT ------------------------------------------------

            Edge const & operator = ( Edge const & other )
            {
                BaseEdge::operator=( other );
                
                this->targetVertex    = other.targetVertex;
                this->nextEdge        = other.nextEdge;
                this->previousEdge    = other.previousEdge;
                this->polygon        = other.polygon;

                return *this;
            }

            // MOVE ASSIGNMENT ------------------------------------------------

            Edge const & operator = ( Edge && other )
            {
                BaseEdge::operator=( other );
                
                this->targetVertex    = other.targetVertex;
                this->nextEdge        = other.nextEdge;
                this->previousEdge    = other.previousEdge;
                this->polygon        = other.polygon;

                return *this;
            }

            // EQUALITY -------------------------------------------------------

            bool const operator == ( Edge const & other ) const
            {
                return this->targetVertex    == other.targetVertex    &&
                       this->nextEdge        == other.nextEdge        &&
                       this->previousEdge    == other.previousEdge    &&
                       this->polygon        == other.polygon;
            }

            // INEQUALITY -----------------------------------------------------

            bool const operator != ( Edge const & other ) const
            {
                return !( *this == other );
            }

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            private:

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PRIVATE METHODS ++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            
            // SET TARGET VERTEX ----------------------------------------------

            void setTargetVertex( VertexIterator vertex )
            {
                targetVertex = vertex;
            }

            // SET NEXT EDGE --------------------------------------------------

            void setNextEdge( EdgeIterator edge )
            {
                nextEdge = edge;
            }
            
            // SET PREVIOUS EDGE ----------------------------------------------

            void setPreviousEdge( EdgeIterator edge )
            {
                previousEdge = edge;
            }

            // SET POLYGON ----------------------------------------------------

            void setPolygon( PolygonIterator polygon )
            {
                this->polygon = polygon;
            }

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PRIVATE DATA +++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            VertexIterator    targetVertex;
            EdgeIterator    nextEdge;
            EdgeIterator    previousEdge;
            PolygonIterator    polygon;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        };

        // POLYGON CLASS ------------------------------------------------------

        class Polygon : public BasePolygon
        {
            public:

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // FRIENDS ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            friend class PolygonGraph< Traits >;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC TYPES +++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // ITERATORS ------------------------------------------------------

            typedef typename Vertex::EdgeIterator        EdgeIterator;
            typedef typename Vertex::ConstEdgeIterator    ConstEdgeIterator;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC METHODS +++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // CONSTRUCTORS ---------------------------------------------------

            Polygon( void ) : BasePolygon()
            {
                // empty
            }

            // COPY CONSTRUCTOR -----------------------------------------------

            Polygon( Polygon const & other ) : BasePolygon( other )
            {
                this->startEdge = other.startEdge;
            }

            // MOVE CONSTRUCTOR -----------------------------------------------

            Polygon( Polygon && other ) : BasePolygon( other )
            {
                this->startEdge = other.startEdge;
            }

            // DESTRUCTOR -----------------------------------------------------

            ~Polygon( void )
            {
                // empty
            }

            // GET START EDGE -------------------------------------------------

            Edge * getStartEdge( void )
            {
                return &( *startEdge );
            }

            Edge const * getStartEdge( void ) const
            {
                return &( *startEdge );
            }

            // GET EDGE COUNT -------------------------------------------------

            size_type const getEdgeCount( void ) const
            {
                Edge * startEdge = &( *startEdge );
                Edge * currentEdge = startEdge;
                size_type edgeCount = 0;

                do
                {
                    ++edgeCount;
                    currentEdge = currentEdge->getNextEdge();
                }
                while( currentEdge != startEdge );

                return edgeCount;
            }

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PUBLIC OPERATORS +++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // COPY ASSIGNMENT ------------------------------------------------

            Polygon const & operator = ( Polygon const & other )
            {
                BasePolygon::operator=( other );

                this->startEdge = other.startEdge;

                return *this;
            }

            // MOVE ASSIGNMENT ------------------------------------------------

            Polygon const & operator = ( Polygon && other )
            {
                BasePolygon::operator=( other );
                
                this->startEdge = other.startEdge;

                return *this;
            }

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            private:

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PRIVATE METHODS ++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // SET START EDGE -------------------------------------------------

            void setStartEdge( EdgeIterator edge )
            {
                this->startEdge = edge;
            }

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // PRIVATE DATA +++++++++++++++++++++++++++++++++++++++++++++++++++
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            EdgeIterator startEdge;

            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        };

        // EDGE ITERATOR ------------------------------------------------------

        typedef typename Vertex::EdgeIterator EdgeIterator;
        typedef typename Vertex::ConstEdgeIterator ConstEdgeIterator;

        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        private:
        
        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        // PRIVATE TYPES ++++++++++++++++++++++++++++++++++++++++++++++++++++++
        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        // CONTAINERS ---------------------------------------------------------

        typedef std::list< Vertex > VertexList;
        typedef std::list< Polygon > PolygonList;

        // ITERATORS ----------------------------------------------------------

        typedef typename VertexList::iterator VertexListIterator;
        typedef typename PolygonList::iterator PolygonListIterator;

        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        public:

        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        // PUBLIC METHODS +++++++++++++++++++++++++++++++++++++++++++++++++++++
        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        // CONSTRUCTORS -------------------------------------------------------

        PolygonGraph( void )
        {
            vertices = new VertexList();
            polygons = new PolygonList();
        }

        // COPY CONSTRUCTOR ---------------------------------------------------

        PolygonGraph( PolygonGraph< Traits > const & other )
        {
            class MapHash
            {
                public:

                std::size_t const
                operator () ( ConstVertexIterator const & it ) const
                {
                    return &( *it );
                }
            };

            typedef std::unordered_map
            <
                ConstVertexIterator,
                VertexIterator,
                MapHash
            >
            VertexMap;

            typedef typename VertexMap::const_iterator VertexMapIter;

            typedef std::pair
            <
                ConstVertexIterator,
                VertexIterator
            >
            VertexMapEntry;

            // Create containers

            this->vertices = new VertexList();
            this->polygons = new PolygonList();

            // Create vertex map

            VertexMap vertexMap;

            // Add all vertices from other graph

            ConstVertexIterator otherVertIt = other.cbeginVertices();
            ConstVertexIterator otherVertItEnd = other.cendVertices();
            VertexMapEntry mapEntry;
            VertexIterator vertIt;

            while( otherVertIt != otherVertItEnd )
            {
                vertIt = addVertex( *otherVertIt );
                mapEntry.first = otherVertIt;
                mapEntry.second = vertIt;
                vertexMap.insert( mapEntry );
                ++otherVertIt;
            }

            // Add all polygons from other graph

            ConstPolygonIterator otherPolyIt = other.cbeginPolygons();
            ConstPolygonIterator otherPolyItEnd = other.cendPolygons();
            Edge const * otherCurrentEdge = nullptr;
            Edge const * otherStartEdge = nullptr;
            std::list< VertexIterator > vertices;
            Edge * currentEdge = nullptr;
            VertexMapIter vertexMapIter;
            PolygonIterator polyIter;

            while( otherPolyIt != otherPolyItEnd )
            {
                vertices.clear();

                // Add mapped vertices of current polygon to list

                otherCurrentEdge =
                    otherPolyIt->getStartEdge()->getPreviousEdge();
                otherStartEdge = otherCurrentEdge;

                do
                {
                    // Find mapped vertex for current edge

                    vertexMapIter = 
                        vertexMap.find( otherCurrentEdge->getTargetVertex() );

                    // Add mapped vertex to list

                    vertices.push_back( vertexMapIter->second );

                    // Advance to next edge

                    otherCurrentEdge = otherCurrentEdge->getNextEdge();
                }
                while( otherCurrentEdge != otherStartEdge );

                // Add polygon to graph

                polyIter = addPolygon( vertices, *otherPolyIt );

                // Copy edge data to new polygon

                otherCurrentEdge = otherCurrentEdge->getNextEdge();
                otherStartEdge = otherCurrentEdge;
                currentEdge = polyIter->getStartEdge();

                do
                {
                    // Assign data from source edge to new edge

                    static_cast< BaseEdge & >( *currentEdge ) =
                        static_cast< BaseEdge & >( otherCurrentEdge );
                    
                    // Advance edge iterators

                    otherCurrentEdge = otherCurrentEdge->getNextEdge();
                    currentEdge = currentEdge->getNextEdge();
                }
                while( otherCurrentEdge != otherStartEdge );

                // Advance to next polygon

                ++otherPolyIt;
            }
        }

        // MOVE CONSTRUCTOR ---------------------------------------------------

        PolygonGraph( PolygonGraph && other )
        {
            this->vertices = other.vertices;
            this->polygons = other.polygons;

            other.polygons = nullptr;
            other.vertices = nullptr;
        }

        // DESTRUCTOR ---------------------------------------------------------

        ~PolygonGraph( void )
        {
            clear();
            
            delete vertices;
            delete polygons;

            vertices = nullptr;
            polygons = nullptr;
        }

        // ADD VERTEX ---------------------------------------------------------

        VertexIterator addVertex( void )
        {
            return addVertex( BaseVertex() );
        }

        VertexIterator addVertex( BaseVertex const & baseVertex )
        {
            vertices->push_back( Vertex() );
            VertexListIterator it = vertices->end(); --it;
            static_cast< BaseVertex & >( *it ) = baseVertex;
            return VertexIterator( it );
        }

        // REMOVE VERTEX ------------------------------------------------------

        VertexIterator removeVertex( VertexIterator vertex )
        {
            typedef std::list< PolygonIterator > PolyIterList;
            typedef typename PolyIterList::iterator PolyIterIt;
            
            // Get all dependent polygons

            EdgeIterator edgeItEnd = vertex->endEdges();
            EdgeIterator edgeIt = vertex->beginEdges();
            PolyIterList dependentPolygons;

            while( edgeIt != edgeItEnd )
            {
                dependentPolygons.push_back( edgeIt->getPolygon() );
                ++edgeIt;
            }

            // Remove all dependent polygons

            PolyIterIt polyIterItEnd = dependentPolygons.end();
            PolyIterIt polyIterIt = dependentPolygons.begin();

            while( polyIterIt != polyIterItEnd )
            {
                removePolygon( *polyIterIt );
                ++polyIterIt;
            }

            // Remove vertex and return next iterator

            return VertexIterator( vertices->erase( vertex.iter ) );
        }

        // REMOVE ISOLATED VERTICES -------------------------------------------

        size_type const removeIsolatedVertices( void )
        {
            // Iterate over vertex list and remove any without edges

            VertexListIterator vertexItEnd = vertices->end();
            VertexListIterator vertexIt = vertices->begin();
            size_type removeCount = 0;

            while( vertexIt != vertexItEnd )
            {
                if( vertexIt->getEdgeCount() == 0 )
                {
                    vertexIt = vertices->erase( vertexIt );
                    ++removeCount;
                }
                else
                {
                    ++vertexIt;
                }
            }

            return removeCount;
        }

        // GET VERTEX COUNT ---------------------------------------------------

        size_type const getVertexCount( void ) const
        {
            return vertices->size();
        }

        // ADD POLYGON --------------------------------------------------------

        PolygonIterator addPolygon
        (
            std::list< VertexIterator > const & vertices
        )
        {
            return addPolygon( vertices, BasePolygon() );
        }

        PolygonIterator addPolygon
        (
            std::list< VertexIterator > const & vertices,
            BasePolygon const & basePolygon
        )
        {
            typedef typename std::list< VertexIterator >::const_iterator
                VertIterIt;
            
            // Ensure polygon has at least three vertices

            if( vertices.size() < 3 )
            {
                return endPolygons();
            }
            
            // Create new polygon

            Polygon polygon;
            static_cast< BasePolygon & >( polygon ) = basePolygon;
            polygons->push_back( polygon );
            PolygonListIterator polyListIt = polygons->end();
            --polyListIt;
            PolygonIterator polygonIt( polyListIt );

            // Create and link edges

            VertIterIt firstVertex = vertices.cbegin();
            VertIterIt secondVertex = firstVertex; ++secondVertex;
            VertIterIt endVertex = vertices.cend();

            Edge * edge = new Edge();
            edge->setPolygon( polygonIt );
            edge->setTargetVertex( *secondVertex );

            EdgeIterator startEdge = ( *firstVertex )->addEdge( edge );
            EdgeIterator previousEdge = startEdge;
            EdgeIterator currentEdge;
            
            ++firstVertex;
            ++secondVertex;

            while( secondVertex != endVertex )
            {
                edge = new Edge( *edge );
                edge->setTargetVertex( *secondVertex );
                currentEdge = ( *firstVertex )->addEdge( edge );

                previousEdge->setNextEdge( currentEdge );
                currentEdge->setPreviousEdge( previousEdge );
                previousEdge = currentEdge;

                ++firstVertex;
                ++secondVertex;
            }

            secondVertex = vertices.cbegin();
            edge = new Edge( *edge );
            edge->setTargetVertex( *secondVertex );

            currentEdge = ( *firstVertex )->addEdge( edge );

            previousEdge->setNextEdge( currentEdge );
            currentEdge->setPreviousEdge( previousEdge );
            currentEdge->setNextEdge( startEdge );
            startEdge->setPreviousEdge( currentEdge );

            // Set start edge of polygon

            polygonIt->setStartEdge( startEdge );

            return polygonIt;
        }

        // REMOVE POLYGON -----------------------------------------------------

        PolygonIterator removePolygon( PolygonIterator polygon )
        {
            // Remove all polygon edges from vertices and delete edges
            
            Edge * startEdge = polygon->getStartEdge();
            EdgeIterator currentEdge = startEdge->nextEdge;
            Edge * edge = &( *currentEdge );
            EdgeIterator nextEdge;

            VertexIterator currentVertex = startEdge->targetVertex;
            VertexIterator nextVertex;

            while( edge != startEdge )
            {
                // Get next edge and vertex

                nextEdge = currentEdge->nextEdge;
                nextVertex = currentEdge->targetVertex;

                // Remove current edge from vertex and deallocate

                currentVertex->removeEdge( currentEdge );
                delete edge;

                // Advance to next edge

                currentEdge = nextEdge;
                currentVertex = nextVertex;
                edge = &( *currentEdge );
            }

            // Remove final edge from vertex and deallocate

            currentVertex->removeEdge( currentEdge );
            delete edge;

            // Remove polygon from list and return iterator to next

            return PolygonIterator( polygons->erase( polygon.iter ) );
        }

        // GET POLYGON COUNT --------------------------------------------------

        size_type const getPolygonCount( void ) const
        {
            return polygons->size();
        }

        // BEGIN VERTICES -----------------------------------------------------

        VertexIterator beginVertices( void )
        {
            return VertexIterator( vertices->begin() );
        }

        ConstVertexIterator cbeginVertices( void ) const
        {
            return ConstVertexIterator
            (
                const_cast< VertexList * >( vertices )->begin()
            );
        }

        // END VERTICES -------------------------------------------------------

        VertexIterator endVertices( void )
        {
            return VertexIterator( vertices->end() );
        }

        ConstVertexIterator cendVertices( void ) const
        {
            return ConstVertexIterator
            (
                const_cast< VertexList * >( vertices )->end()
            );
        }

        // BEGIN POLYGONS -----------------------------------------------------

        PolygonIterator beginPolygons( void )
        {
            return PolygonIterator( polygons->begin() );
        }

        ConstPolygonIterator cbeginPolygons( void ) const
        {
            return ConstPolygonIterator
            (
                const_cast< PolygonList * >( polygons )->begin()
            );
        }

        // END POLYGONS -------------------------------------------------------

        PolygonIterator endPolygons( void )
        {
            return PolygonIterator( polygons->end() );
        }

        ConstPolygonIterator cendPolygons( void ) const
        {
            return ConstPolygonIterator
            (
                const_cast< PolygonList * >( polygons )->end()
            );
        }

        // CLEAR --------------------------------------------------------------

        void clear( void )
        {
            // Remove all polygons

            PolygonIterator polyItEnd = endPolygons();
            PolygonIterator polyIt = beginPolygons();

            while( polyIt != polyItEnd )
            {
                polyIt = removePolygon( polyIt );
            }

            // Clear vertices

            vertices->clear();
        }

        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        // PUBLIC OPERATORS +++++++++++++++++++++++++++++++++++++++++++++++++++
        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        // COPY ASSIGNMENT ----------------------------------------------------

        PolygonGraph< Traits > const & operator =
            ( PolygonGraph< Traits > const & other )
        {
            PolygonGraph< Traits > copy( *other );

            clear();

            delete this->vertices;
            delete this->polygons;

            this->vertices = copy.vertices;
            this->polygons = copy.polygons;

            copy.vertices = nullptr;
            copy.polygons = nullptr;

            return *this;
        }

        // MOVE ASSIGNMENT ----------------------------------------------------

        PolygonGraph< Traits > const & operator =
            ( PolygonGraph< Traits > && other )
        {
            clear();
            
            delete this->vertices;
            delete this->polygons;

            this->vertices = other.vertices;
            this->polygons = other.polygons;

            other.vertices = nullptr;
            other.polygons = nullptr;

            return *this;
        }

        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        private:

        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        // PRIVATE DATA +++++++++++++++++++++++++++++++++++++++++++++++++++++++
        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        VertexList * vertices;
        PolygonList * polygons;

        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    };

    // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#endif // POLYGON_GRAPH_H
