<?php

/**
 * @file
 * Theme implementation of search widget display.
 */
?>

<div class="search--widget is-course">
  <div class="search--widget-inner">
    <div class="search--lock-overlay is-active"></div>
    <div class="search--filter-wrapper">
      <div class="search--filter-wrapper-inner">
        <div class="search--filter-text">
          <input type="text" id="search" name="search" value="" size="60" maxlength="128" class="search--filter-search-text">
          <input class="search--filter-search-submit" type="submit" id="search-submit" name="search-submit" value="Search">
        </div>
      </div>
    </div>
    <div class="search--filter-wrapper is-active">
      <div class="search--filter-wrapper-inner">
        <div class="search--filter-list">
          <a href="#" class="search--filter-label">Educational goals</a>
          <div class="search--filter-dropdown is-visible">
            <div class="search--filter-dropdown-inner">
              <div class="search--filter-dropdown-header">Educational goals <a href="#" class="search--filter-dropdown-header-close"><img src="data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiA/PjwhRE9DVFlQRSBzdmcgIFBVQkxJQyAnLS8vVzNDLy9EVEQgU1ZHIDEuMS8vRU4nICAnaHR0cDovL3d3dy53My5vcmcvR3JhcGhpY3MvU1ZHLzEuMS9EVEQvc3ZnMTEuZHRkJz48c3ZnIGhlaWdodD0iNTEycHgiIGlkPSJMYXllcl8xIiBzdHlsZT0iZW5hYmxlLWJhY2tncm91bmQ6bmV3IDAgMCA1MTIgNTEyOyIgdmVyc2lvbj0iMS4xIiB2aWV3Qm94PSIwIDAgNTEyIDUxMiIgd2lkdGg9IjUxMnB4IiB4bWw6c3BhY2U9InByZXNlcnZlIiB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHhtbG5zOnhsaW5rPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5L3hsaW5rIj48cGF0aCBkPSJNNDM3LjUsMzg2LjZMMzA2LjksMjU2bDEzMC42LTEzMC42YzE0LjEtMTQuMSwxNC4xLTM2LjgsMC01MC45Yy0xNC4xLTE0LjEtMzYuOC0xNC4xLTUwLjksMEwyNTYsMjA1LjFMMTI1LjQsNzQuNSAgYy0xNC4xLTE0LjEtMzYuOC0xNC4xLTUwLjksMGMtMTQuMSwxNC4xLTE0LjEsMzYuOCwwLDUwLjlMMjA1LjEsMjU2TDc0LjUsMzg2LjZjLTE0LjEsMTQuMS0xNC4xLDM2LjgsMCw1MC45ICBjMTQuMSwxNC4xLDM2LjgsMTQuMSw1MC45LDBMMjU2LDMwNi45bDEzMC42LDEzMC42YzE0LjEsMTQuMSwzNi44LDE0LjEsNTAuOSwwQzQ1MS41LDQyMy40LDQ1MS41LDQwMC42LDQzNy41LDM4Ni42eiIvPjwvc3ZnPg=="></a></div>
              <div class="search--filter-dropdown-content">
                <input type="checkbox" name="age" value="0 år" />Alsidig personlig udvikling<br/>
                <input type="checkbox" name="age" value="1 år" />Krop og bevægelse<br/>
                <input type="checkbox" name="age" value="2 år" />Kulturelle udtryksformer og værdier<br/>
                <input type="checkbox" name="age" value="3 år" />Natur og naturfænomener<br/>
                <input type="checkbox" name="age" value="4 år" />Sociale kompetencer<br/>
                <input type="checkbox" name="age" value="5 år" />Sproglig udvikling<br/>
              </div>
              <a href="#" class="search--filter-dropdown-submit">Anvend</a>
            </div>
          </div>
        </div>
      </div>
    </div>
    <div class="search--filter-wrapper">
      <div class="search--filter-wrapper-inner">
        <div class="search--filter-list">
          <a href="#" class="search--filter-label">Age</a>
        </div>
      </div>
    </div>
    <div class="search--filter-wrapper">
      <div class="search--filter-wrapper-inner">
        <div class="search--filter-span">
          <div class="search--filter-span-wrapper"><label class="search--filter-span-label">From</label><input type="text" id="search" name="search" value="" size="60" maxlength="128" class="search--filter-span-text"></div>
          <div class="search--filter-span-wrapper"><label class="search--filter-span-label">To</label><input type="text" id="search" name="search" value="" size="60" maxlength="128" class="search--filter-span-text"></div>
        </div>
      </div>
    </div>
    <div class="search--filter-wrapper">
      <div class="search--filter-wrapper-inner">
        <div class="search--filter-list">
          <a href="#" class="search--filter-label">Visit/Course</a>
        </div>
      </div>
    </div>
    <div class="search--filter-wrapper">
      <div class="search--filter-wrapper-inner">
        <div class="search--filter-list">
          <a href="#" class="search--filter-label">Price</a>
          <div class="search--filter-dropdown">
            <div class="search--filter-dropdown-inner">
              <div class="search--filter-dropdown-header">Price <a href="#" class="search--filter-dropdown-header-close"><img src="data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiA/PjwhRE9DVFlQRSBzdmcgIFBVQkxJQyAnLS8vVzNDLy9EVEQgU1ZHIDEuMS8vRU4nICAnaHR0cDovL3d3dy53My5vcmcvR3JhcGhpY3MvU1ZHLzEuMS9EVEQvc3ZnMTEuZHRkJz48c3ZnIGhlaWdodD0iNTEycHgiIGlkPSJMYXllcl8xIiBzdHlsZT0iZW5hYmxlLWJhY2tncm91bmQ6bmV3IDAgMCA1MTIgNTEyOyIgdmVyc2lvbj0iMS4xIiB2aWV3Qm94PSIwIDAgNTEyIDUxMiIgd2lkdGg9IjUxMnB4IiB4bWw6c3BhY2U9InByZXNlcnZlIiB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHhtbG5zOnhsaW5rPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5L3hsaW5rIj48cGF0aCBkPSJNNDM3LjUsMzg2LjZMMzA2LjksMjU2bDEzMC42LTEzMC42YzE0LjEtMTQuMSwxNC4xLTM2LjgsMC01MC45Yy0xNC4xLTE0LjEtMzYuOC0xNC4xLTUwLjksMEwyNTYsMjA1LjFMMTI1LjQsNzQuNSAgYy0xNC4xLTE0LjEtMzYuOC0xNC4xLTUwLjksMGMtMTQuMSwxNC4xLTE0LjEsMzYuOCwwLDUwLjlMMjA1LjEsMjU2TDc0LjUsMzg2LjZjLTE0LjEsMTQuMS0xNC4xLDM2LjgsMCw1MC45ICBjMTQuMSwxNC4xLDM2LjgsMTQuMSw1MC45LDBMMjU2LDMwNi45bDEzMC42LDEzMC42YzE0LjEsMTQuMSwzNi44LDE0LjEsNTAuOSwwQzQ1MS41LDQyMy40LDQ1MS41LDQwMC42LDQzNy41LDM4Ni42eiIvPjwvc3ZnPg=="></a></div>
              <div class="search--filter-dropdown-content">
                <input type="checkbox" name="free" value="free" />Gratis<br/>
                <input type="checkbox" name="age" value="-100" />> 100 kr.<br/>
                <input type="checkbox" name="age" value="100-300" />100 - 300 kr.<br/>
                <input type="checkbox" name="age" value="300-500" />300 - 500 kr.<br/>
                <input type="checkbox" name="age" value="500-1000" />500 - 1000 kr.<br/>
                <input type="checkbox" name="age" value="1000+" />1000kr. <<br/>
              </div>
              <a href="#" class="search--filter-dropdown-submit">Anvend</a>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
  <div class="search--widget-filters">
    <div class="search--widget-filters-inner">
      <a href="#" class="search--widget-filters-open">Flere filtreringsmuligheder</a>
    </div>
  </div>
  <div class="search--widget-selected">
    <div class="search--widget-selected-inner">
      <a href="#" class="search--widget-selected-item">Kulturelle udtryksformer og værdier</a>
      <a href="#" class="search--widget-selected-item">4 år</a>
      <a href="#" class="search--widget-selected-item">5 år</a>
      <a href="#" class="search--widget-selected-item">Visit</a>
      <a href="#" class="search--widget-selected-item">Gratis</a>
      <a href="#" class="search--widget-selected-item">> 100 kr</a>
      <a href="#" class="search--widget-selected-item">100 - 300 kr.</a>
      <a href="#" class="search--widget-selected-item">100 - 300 kr.</a>
      <a href="#" class="search--widget-selected-item">100 - 300 kr.</a>
    </div>
  </div>
</div>