/**
 * @file
 * Modify multidimensional selects.
 */

/**
 * Attaches javascript to handle multidimensional selects.
 */
(function ($) {
  // Called when the document has finished loading.
  Drupal.behaviors.ulfMultidimensionalSelect = {
    attach: function (context, settings) {
      var form = $('.ulf-forms--multidimensional-select .form-checkboxes');

      var expression = new RegExp('^' + '-');
      var child_inputs = form.find("label").filter(function () {
        return expression.test($.trim($(this).text()));
      });

      // Set classes for child and parent elements in taxonomy.
      var number_of_parents = 0;
      child_inputs.each(function () {
        var self = $(this);
        var parent = self.parent();

        // Replace first - character in string.
        self.text(self.text().replace(expression, ''));
        // Add class to parent.
        parent.addClass('ulf-forms--child-select');

        var input = parent.find('input');

        if (!input.prop('checked')) {
          parent.addClass('ulf-forms--child-select-hidden');
        }

        var prev = parent.prev();

        if (!prev.hasClass('ulf-forms--child-select')) {
          number_of_parents++;
          prev.addClass('ulf-forms--parent-select')
          .addClass('ulf-forms--select-group-' + number_of_parents);
          parent.addClass('ulf-forms--select-group-' + number_of_parents);
        }
        else {
          parent.addClass('ulf-forms--select-group-' + number_of_parents);
        }
      });

      // Set listeners and classes for parent elements.
      $('.ulf-forms--parent-select').each(function () {
        var self = $(this);
        var classes = self.prop('class');
        var group = classes.match(/ulf-forms--select-group-\d+/g);
        var selfInput = self.find('input');

        selfInput.on('change', function () {
          var input = $(this);

          if (!input.prop('checked')) {
            var child_selects = $('.' + group + '.ulf-forms--child-select');

            child_selects.addClass('ulf-forms--child-select-hidden');

            child_selects.each(function () {
              $(this).find('input').removeAttr('checked');
            });

            self.removeClass('is-checked');
          }
          else {
            $('.' + group + '.ulf-forms--child-select')
            .removeClass('ulf-forms--child-select-hidden');
            self.addClass('is-checked');
          }
        });

        if (selfInput.prop('checked')) {
          $('.' + group + '.ulf-forms--child-select')
          .removeClass('ulf-forms--child-select-hidden');
          self.addClass('is-checked');
        }
        else {
          self.removeClass('is-checked');
        }
      });
    }
  };
}(jQuery));
