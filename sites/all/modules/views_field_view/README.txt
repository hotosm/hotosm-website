This module allows you to embed a View as a field in another View.

The View in the view-field can accept argument values from other fields of the parent View, using tokens.

Here's how:

1. Before you can add a view-field to a "parent" view, you must create a "child" view.
2. Add arguments to that child view. The parent view will be passing argument values to
   the child so that the child knows what to display. No other settings are necessary,
   but validators and "argument not present" could be set.
3. Create a "parent" view, if not already existing.
4. Add child view (Global:View field). The field must be toward the bottom of the field list,
   or at least underneath the fields that are going to be used as arguments.
   (E.g., "node id" might be used as an match between the parent and child views,
   so put the "node id" field before your Global:View field in the list.)
5. Select which View and Display to use for the child data (will require doing this in 2 steps
   - the field must be saved before the display selection is available).
6. Find which tokens are available by looking at the "Replacement patterns" list right below the Arguments setting.
   Type the token replacements, in order, separated by a comma, as the arguments for that view field.
   These values will be passed to the child. Make sure each field you are passing as an argument is completely clean,
   as in: no label, no formatting, nothing that would pass into the argument other than the desired text or number.
