chrome.action.onClicked.addListener((tab) => {
  if (tab.url.includes('https://codeforces.com/mashup/new')) {
    chrome.scripting.executeScript({
      target: { tabId: tab.id },
      func: runMashupScript
    });
  }
})

function runMashupScript() {
    /* Randomize array in-place using Durstenfeld shuffle algorithm */
  function shuffleArray(array) {
    for (var i = array.length - 1; i > 0; i--) {
      var j = Math.floor(Math.random() * (i + 1));
      var temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }

  var contest_id = document.getElementById("contestName").value;
  var duration = document.getElementById("contestDuration").value;

  document.getElementById("contestName").value = contest_id + " mashup";
  document.getElementById("contestDuration").value = duration;

  var cnt = 0;

  problems = ["A", "B", "C", "D", "E", "F"];

  shuffleArray(problems);
  
  document.body.style.visibility = "hidden";

  function addProblem() {
    if (cnt == problems.length) {
      document.querySelector("._MashupContestEditFrame_saveMashup > .submit").click();
      return;
    }
    document.querySelector("[name='problemQuery']").value =
      contest_id + "-" + problems[cnt];
    cnt++;
    document.querySelector("._MashupContestEditFrame_addProblemLink").click();
    setTimeout(addProblem, 1000);
  }


  addProblem();
}