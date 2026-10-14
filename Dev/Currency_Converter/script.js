import {countryList} from './code.js';

const selectElements = document.querySelectorAll("select");

for (const countryCode in countryList) {

    let flag1 = document.createElement("option");
    flag1.value = countryCode;
    flag1.innerText = countryList[countryCode];
    selectElements[0].append(flag1);
    
    let flag2 = document.createElement("option");
    flag2.value = countryCode;
    flag2.innerText =countryList[countryCode];
    selectElements[1].append(flag2);

}

const flagimg = document.querySelectorAll("img");

const getcountryflag = (countrycode, num) => {
    flagimg[num].src = `https://flagsapi.com/${countrycode}/flat/64.png`;
};

selectElements[0].addEventListener("change", () => {
    getcountryflag(selectElements[0].value.toUpperCase(), 0);
});

selectElements[1].addEventListener("change", () => {
    getcountryflag(selectElements[1].value.toUpperCase(), 1);
});