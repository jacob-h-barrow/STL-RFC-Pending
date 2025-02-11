using InIt = InputIterator;
using ForIt = ForwardIterator;
using RanIt = RandomAccessIterator;
using OutIt = OutputIterator;
using BiIt = BidirectionalIterator;
using UFxn = UnaryFunction;
using BFxn = BinaryFunction;
using Alloc = Allocator;
using BPred = BinaryPredicate;
using UPred = UnaryPredicate;
using InIt_Pair = std::pair<InIt1, InIt2>;
using ForIt_Pair = std::pair<ForIt1, ForIt2>;
using Op = Operation;
using ptr_to_ufxn = pointer_to_unary_function;
using Difference_Type = iterator_traits<InIt>::difference_type;

replacing (InIt1 src_l1, InIt2 src_f2, InIt2 src_l2, OutIt dst_f, Compare cmp?) with TupleArgs1;
replacing (ForIt first, ForIt last, T_const& value, Compare cmp?) with TupleArgs2;
replacing (InIt first, InIt last) with TupleArgs3;
replacing (InIt1, Init2, OutIt, Compare?) with TemplateArgs1;
replacing (ForIt, T, Compare?) with TemplateArgs2;
replacing (InIt1, InIt2, BPred?) with TemplateArgs3;

/*
   Redefinitions
    template = []
    Optional = Variable?
    Constant =  Variable_const
    Class = c_Variable, unless its in a template which can be dropped (all require classes)
    Prototypes are allowed: replacing XXX with YYY
        - **Variable unpackes this tuple as args, not required in a template definition
*/ 

// Utility Fxns
[Op, T]
binder1st<Op> bind1st(const Op& op, const T& x);
binder2nd<Op> bind2nd(const Op& op, const T& x);

[Arg | (Arg1, Arg2), Result?]
ptr_to_ufxn<Arg, Result> ptr_fun(Result(*f)(Arg));
ptr_to_ufxn<Arg1, Arg2, Result> ptr_fun(Result(*F)(Arg1, Arg2));

// Merging STL Algos
//// min and max templates are both the same and can be containers like a.begin(), etc.
[T, Compare?]
T_const& min(T_const& a, T& b, Compare cmp?);

//// min_element and max_element is basically the same, minus an iterator returned
[ForIt, Compare?]
ForIt min_element(ForIt first, ForIt last, Compare cmp?);

[Init1, Init2, Compare?]
bool includes(**TupleArgs1);

[TemplateArgs1]
OutIt set_XXX(**TupleArgs1);
OutIt merge(**TupleArgs1);

[BiIt, Compare?]
void inplace_merge(BiIt first, BiIt middle, BiIt last, Compare cmp?);

// Sorting STL Algos
//// sort and stable_sort have the same interface
[RanIt, Compare?]
void sort(RanIt first, RanIt last, Compare cmp?);

[TemplateArgs2]
bool binary_search(**TupleArgs2);
ForIt_Pair equal_range(**TupleArgs2);
ForIt upper_bound(**TupleArgs2);
ForIt lower_bound(**TupleArgs2);

// Non-Modifying STL Algps
//// replacing (InIt first, InIt last) with TupleArgs3;
[InIt, UFxn]
UFxn for_each(**TupleArgs3, UFxn f);

[InIt, T]
InIt find(**TupleArgs3, T_const& value);
Difference_Type count(**TupleArgs3, T_const& value);

[InIt, UPred]
InIt find_if(**TupleArgs3, UPred p);
Difference_Type count_if(**TupleArgs3, UPred p);

//// replacing (InIt1, InIt2, BPred?) with TemplateArgs3;
[TemplateArgs3]
InIt_Pair mismatch(**TupleArgs3, InIt2 first2, BPred p?);
bool equal(**TupleArgs3, InIt first2, BPred p?);

[ForIt, Size, T, BPred?]
ForIt search_n(ForIt first, ForIt last, Size count, T_const& value, BPred p?);

[ForIt1, ForIt2, BPred?]
ForIt1 find_first_of(ForIt1 src_f1, ForIt1 src_l1, ForIt2 src_f2, ForIt2 src_l2, BPred p?);
